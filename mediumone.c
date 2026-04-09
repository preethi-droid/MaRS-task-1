#include <stdio.h>
#include <math.h>

int main() {
    
    double x_cam, y_cam, z_cam, rover_x, rover_y, rover_z, x_angle, y_angle, z_angle;
    double rx, ry, rz, x1, y1, z1, x2, y2, z2, x3, y3, z3, x_world, y_world, z_world;

    printf("Enter camera coordinates (x y z): ");
    scanf("%lf %lf %lf", &x_cam, &y_cam, &z_cam);

    printf("Enter rover position (x y z): ");
    scanf("%lf %lf %lf", &rover_x, &rover_y, &rover_z);

    printf("Enter rover rotation angles (x y z in degrees): ");
    scanf("%lf %lf %lf", &x_angle, &y_angle, &z_angle);

    //converting degrees to radians
    rx = x_angle * M_PI / 180.0;
    ry = y_angle * M_PI / 180.0;
    rz = z_angle * M_PI / 180.0;

    //rotation around x axis
    y1 = y_cam * cos(rx) - z_cam * sin(rx);
    z1 = y_cam * sin(rx) + z_cam * cos(rx);
    x1 = x_cam;

    //rotation around y axis
    x2 = x1 * cos(ry) + z1 * sin(ry);
    z2 = -x1 * sin(ry) + z1 * cos(ry);
    y2 = y1;

    //rotation around z axis
    x3 = x2 * cos(rz) - y2 * sin(rz);
    y3 = x2 * sin(rz) + y2 * cos(rz);
    z3 = z2;

    //translation
    x_world = x3 + rover_x;
    y_world = y3 + rover_y;
    z_world = z3 + rover_z;

    printf("\nWorld Coordinates:\n");
    printf("x = %.3lf\n", x_world);
    printf("y = %.3lf\n", y_world);
    printf("z = %.3lf\n", z_world);

    return 0;
}
