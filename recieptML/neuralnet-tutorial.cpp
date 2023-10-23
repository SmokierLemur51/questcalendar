
#include <vector>

class Neuron;

typedef std::vector<Neuron> Layer;


class Net {

public:
	Net(const  std::vector<unsigned> topology);
	void feedForward(const std::vector<double> &inputVals);
	void backProp(const std::vector<double> &targetVals);
	void getResults(std::vector<double>resultVals) const; 

private:
	std::vector<Layer> = m_layers;
};


Net::Net(const std::vector<unsigned> &topology)
{
	unsigned numLayers = topology.size();
	for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum) {
		m_layers.push_back(Layer());

		// we have made a new layer, fill it with neurons, and 
		// add a bias neuron to the layer:
		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum) {
			m_layers.back().push_back(Neuron()); // 
		} 
	}
};

int main() {

	std::vector<unsigned> topology;
	Net mynet(topology);

	std::vector<double> inputVals;
	mynet.feedForward(inputVals);

	std::vector<double> targetVals;
	mynet.backProp(targetVals);
	
	std::vector<double> resultVals;
	mynet.getResults(resultVals);
}