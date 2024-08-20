#include "vec3.h"
#include "mesh.h"

// This is an example of reading and rotataing a model using this
// Note that it works with both binary and ascii stl format

const int STEPS_COUNT = 300;
const float ROTATIONAL_SPEED = 1.2f; // This is simply 360/300
const Vec3 ROTATIONAL_AXIS(1.f,0.f,0.f);
const int DIGIT_COUNT = 3;

// Helper function, transforming an int into a string of fixed length
std::string fixedLength(int value, int digits = DIGIT_COUNT) {
    std::string result = std::to_string(value);
    while (result.length() < DIGIT_COUNT)
    {
        result = "0" + result;
    }
    return result;
}

int main() {
    Mesh mesh_src;
	mesh_src = stl_read("./testModels/NewOda03.stl");
	
    for (size_t step = 0; step < STEPS_COUNT; step++)
    {
        mesh_src.rotate(ROTATIONAL_SPEED, ROTATIONAL_AXIS);
        std::string fName = "./results/OdaRotated_" + fixedLength(step) + ".stl";
        mesh_src.stl_write(fName);
    }
}