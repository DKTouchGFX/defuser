#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0), code(3486)
{

}

void Model::tick()
{

}

void Model::setCode(int code)
{
    this->code = code;
    if (modelListener)
    {
        modelListener->codeChanged(code);
    }
}

int Model::getCode()
{
    return code;
}
