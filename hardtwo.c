def find_distance(perceived_width):
    import math

    #values given
    real_width = 17.0
    image_width = 1280
    fov = 55  # degrees

    #converting FOV to radians
    fov_rad = math.radians(fov)

    #calculating the focal length
    focal_length = (image_width / 2) / math.tan(fov_rad / 2)

    #distance formula
    distance = (real_width * focal_length) / perceived_width

    return distance
