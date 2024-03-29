#include "OctopusPCH.h"
#include "GLDebug.h"

bool Octo::GLCheckError() {
    while (GLenum error = glGetError())
    {
        switch(error) {
            case GL_INVALID_ENUM :
                OCTO_LOG_ERROR("[OpenGL] GL_INVALID_ENUM : An unacceptable value is specified for an enumerated argument.");
                break;
            case GL_INVALID_VALUE :
                OCTO_LOG_ERROR("[OpenGL] GL_INVALID_OPERATION : A numeric argument is out of range.");
                break;
            case GL_INVALID_OPERATION :
                OCTO_LOG_ERROR("[OpenGL] GL_INVALID_OPERATION : The specified operation is not allowed in the current state.");
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION :
                OCTO_LOG_ERROR("[OpenGL] GL_INVALID_FRAMEBUFFER_OPERATION : The framebuffer object is not complete.");
                break;
            case GL_OUT_OF_MEMORY :
                OCTO_LOG_ERROR("[OpenGL] GL_OUT_OF_MEMORY : There is not enough memory left to execute the command.");
                break;
            case GL_STACK_UNDERFLOW :
                OCTO_LOG_ERROR("[OpenGL] GL_STACK_UNDERFLOW : An attempt has been made to perform an operation that would cause an internal stack to underflow.");
                break;
            case GL_STACK_OVERFLOW :
                OCTO_LOG_ERROR("[OpenGL] GL_STACK_OVERFLOW : An attempt has been made to perform an operation that would cause an internal stack to overflow.");
                break;
            default :
                OCTO_LOG_ERROR("[OpenGL] Unrecognized error", error);
        }
        return false;
    }
    return true;
}
