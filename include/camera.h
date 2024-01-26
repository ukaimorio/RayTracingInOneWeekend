#pragma once

#include "rtweekend.h"

#include "hittable.h"
#include "material.h"

#include <iostream>

class camera
{
public:
    double aspect_ratio = 1.0;  // 图像宽高比
    int image_width = 100;      // 渲染图像的宽度（像素数量）
    int samples_per_pixel = 10; // 每个像素的随机采样次数
    int max_depth = 10;         // 光线在场景中的最大反射次数
    color background;

    double vfov = 90;                   // 垂直视角（视野）
    point3 lookfrom = point3(0, 0, -1); // 摄像机位置
    point3 lookat = point3(0, 0, 0);    // 摄像机朝向
    vec3 vup = vec3(0, 1, 0);           // 摄像机的上方向

    double defocus_angle = 0; // 每个像素的光线偏转角度
    double focus_dist = 10;   // 摄像机到完美焦点平面的距离

    void render(const hittable &world)
    {
        initialize();

        std::cout << "P3\n"
                  << image_width << ' ' << image_height << "\n255\n";

        for (int j = 0; j < image_height; ++j)
        {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for (int i = 0; i < image_width; ++i)
            {
                color pixel_color(0, 0, 0);
                for (int sample = 0; sample < samples_per_pixel; ++sample)
                {
                    ray r = get_ray(i, j);
                    pixel_color += ray_color(r, max_depth, world);
                }
                write_color(std::cout, pixel_color, samples_per_pixel);
            }
        }

        std::clog << "\rDone.                 \n";
    }

private:
    int image_height;    // 渲染图像的高度
    point3 center;       // 摄像机中心
    point3 pixel00_loc;  // 左上角像素的位置
    vec3 pixel_delta_u;  // 向右像素的偏移
    vec3 pixel_delta_v;  // 向下像素的偏移
    vec3 u, v, w;        // 摄像机坐标系的基向量
    vec3 defocus_disk_u; // 散焦光圈的水平半径
    vec3 defocus_disk_v; // 散焦光圈的垂直半径

    void initialize()
    {
        image_height = static_cast<int>(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        center = lookfrom;

        auto theta = degrees_to_radians(vfov);
        auto h = tan(theta / 2);
        auto viewport_height = 2 * h * focus_dist;
        auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);

        w = (lookfrom - lookat).normalize();
        u = (cross(vup, w)).normalize();
        v = cross(w, u);

        vec3 viewport_u = viewport_width * u;
        vec3 viewport_v = viewport_height * -v;

        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        auto viewport_upper_left = center - (focus_dist * w) - viewport_u / 2 - viewport_v / 2;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

        auto defocus_radius = focus_dist * tan(degrees_to_radians(defocus_angle / 2));
        defocus_disk_u = u * defocus_radius;
        defocus_disk_v = v * defocus_radius;
    }

    ray get_ray(int i, int j) const
    {
        auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
        auto pixel_sample = pixel_center + pixel_sample_square();

        auto ray_origin = (defocus_angle <= 0) ? center : defocus_disk_sample();
        auto ray_direction = pixel_sample - ray_origin;
        auto ray_time = random_double();

        return ray(ray_origin, ray_direction, ray_time);
    }

    vec3 pixel_sample_square() const
    {
        // 返回原点周围正方形内的随机点。
        auto px = -0.5 + random_double();
        auto py = -0.5 + random_double();
        return (px * pixel_delta_u) + (py * pixel_delta_v);
    }

    point3 defocus_disk_sample() const
    {
        // 返回摄像机散焦光圈内的随机点。
        auto p = random_in_unit_disk();
        return center + (p[0] * defocus_disk_u) + (p[1] * defocus_disk_v);
    }

    color ray_color(const ray &r, int depth, const hittable &world) const
    {
        hit_record rec;

        if (depth <= 0)
            return color(0, 0, 0);

        // If the ray hits nothing, return the background color.
        if (!world.hit(r, interval(0.001, infinity), rec))
            return background;

        ray scattered;
        color attenuation;
        color color_from_emission = rec.mat->emitted(rec.u, rec.v, rec.p);

        if (!rec.mat->scatter(r, rec, attenuation, scattered))
            return color_from_emission;

        color color_from_scatter = attenuation * ray_color(scattered, depth - 1, world);

        return color_from_emission + color_from_scatter;
    }
};
