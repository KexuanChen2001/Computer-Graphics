// Transform.cpp: implementation of the Transform class.

#include "Transform.h"

//Please implement the following functions:

// return the rotation matrix which is rotating "degrees" about the axis "axis".  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR Assgin1 HERE

    /* Sample code to revise. Pls refer to the slide of page 25 on CG4033_03_ transformation.pdf.
    Pls be noted that this is not the right answer.*/

    mat3 first_mat = glm::mat3(
        glm::vec3(1.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 1.0f));
    //If meet the need of changeing the frame, need to change the matrix from the PPT
    mat3 second_mat = glm::mat3(
        glm::vec3(axis.x * axis.x, axis.x * axis.y, axis.x * axis.z),
        glm::vec3(axis.x * axis.y, axis.y * axis.y, axis.y * axis.z),
        glm::vec3(axis.z * axis.x, axis.z * axis.y, axis.z * axis.z));
    mat3 third_mat = glm::mat3(
        glm::vec3(0.0f, -axis.z, axis.y),
        glm::vec3(axis.z, 0.0f, -axis.x),
        glm::vec3(-axis.y, axis.x, 0.0f));
    mat3 rot = cos(glm::radians(degrees)) * first_mat +
        (1-cos(glm::radians(degrees))) * second_mat + 
        sin(glm::radians(degrees)) * third_mat;


    return rot;

    // You will change this return call
    
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR Assign1 HERE   

  /* Sample code to revise. Pls be noted that this is not the right answer.*/
    
    up = up * rotate(degrees, up);
    eye = eye * rotate(degrees, up);
    

}

vec3 u= glm::vec3(0.0f, 0.0f, 0.0f);

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR Assign1 HERE 

    /* Sample code to revise. Pls be noted that this is not the right answer.*/
    glm::vec3 r = glm::normalize(glm::cross(eye, up));//horizontal vector
    //up = glm::normalize(glm::cross(eye, up));//let it be the unit vector (r)
    eye = eye * rotate(degrees, r);
    up = up * rotate(degrees, r);
    
    
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR Assign1 HERE

    /* sample code to revise. Pls follow the code to call the standard glm::lookAt to get your function. 
    Just fill in ... and you will get your right answer.*/
    vec3 eye1 = glm::normalize(glm::vec3(eye.x, eye.y, eye.z));
    vec3 up1 = glm::normalize(glm::vec3(up.x, up.y, up.z));
    vec3 center1 = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::mat4 view = glm::lookAt(eye1, center1, up1);
    return view;
    
    // You will change this return call
    
}

Transform::Transform()
{

}

Transform::~Transform()
{

}