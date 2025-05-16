#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void setCode(int code);
    int getCode();

protected:
    ModelListener* modelListener;

private:
    int code;
};

#endif // MODEL_HPP
