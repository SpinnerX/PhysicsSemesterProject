#pragma once
#include <Core/core.h>
#include <Core/Layer.h>


namespace PhysicsSimulation{

    // Essentially LayerStack is a wrapper of std::vectors of Layers
    // using vector so we can iterate over.
    // for updates we need to iterate through it
    // Not using Stack because we eventually wanna store layers in the middle.
    // So, like some contiguous stack of layers.
    class SIM_API LayerStack{
        using iterator = std::vector<Layer *>::iterator;
    public:
        LayerStack();
        ~LayerStack();

        void pushLayer(Layer* layer);
        void pushOverlay(Layer* overlay);
        void popLayer(Layer* layer);
        void popOverlay(Layer* overlay);

        iterator begin() { return _layers.begin(); }
        iterator end() { return _layers.end(); }
    private:
        std::vector<Layer *> _layers;
       unsigned int _layersInsertIndex = 0;
    };
};