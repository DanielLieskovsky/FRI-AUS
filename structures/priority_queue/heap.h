#pragma once

#include "priority_queue_list.h"
#include "../list/array_list.h"
#include "../utils.h"
#include <stdexcept>

namespace structures
{
	/// <summary> Prioritny front implementovany haldou. Implementujucim typom haldy je struktura ArrayList. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
	template<typename T>
	class Heap : public PriorityQueueList<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		Heap();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Halda, z ktorej sa prevezmu vlastnosti. </param>
		Heap(Heap<T>& other);

		/// <summary> Priradenie struktury. </summary>
		/// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Vlozi prvok s danou prioritou do haldy. </summary>
		/// <param name = "priority"> Priorita vkladaneho prvku. </param>
		/// <param name = "data"> Vkladany prvok. </param>
		void push(int priority, const T& data) override;

		/// <summary> Odstrani prvok s najvacsou prioritou z haldy. </summary>
		/// <returns> Odstraneny prvok. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je halda prazdna. </exception>
		T pop() override;

	protected:
		/// <summary> Vrati index v ArrayList-e, na ktorom sa nachadza prvok s najvacsou prioritou. </summary>
		/// <returns> Index prvku s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je ArrayList prazdny. </exception>
		int indexOfPeek() override;

	private:
		/// <summary> Vrati index v ArrayList-e, na ktorom by sa mal nachadzat otec daneho prvku. </summary>
		/// <param name = "index"> Index prvku, ktoreho otca chceme vratit. </param>
		/// <returns> Index, na ktorom ba sa mal nachadzat otec prvku. </returns>
		int getParentIndex(int index);

		/// <summary> Vrati index v ArrayList-e, na ktorom by mal mat dany prvok syna s najvacsou prioritou. </summary>
		/// <param name = "index"> Index prvku, ktoreho syna chceme vratit. </param>
		/// <returns> Index, na ktorom by sa mal nachadzat syn prvku. </returns>
		int getGreaterSonIndex(int index);
	};

	template<typename T>
	Heap<T>::Heap() :
		PriorityQueueList<T>(new ArrayList<PriorityQueueItem<T>*>())
	{
	}

	template<typename T>
	Heap<T>::Heap(Heap<T>& other) :
		Heap<T>()
	{
		assign(other)
	}

	template<typename T>
	inline Structure& Heap<T>::assign(Structure& other)
	{
		return PriorityQueueList<T>::assign(dynamic_cast<PriorityQueueList<T>&>(other));
	}

	template<typename T>
	void Heap<T>::push(int priority, const T& data)
	{
		//TODO 06: Heap
		//throw std::runtime_error("Heap<T>::push: Not implemented yet.");

		list_->add(new PriorityQueueItem<T>(priority, data));

		int index = list_->size() - 1;
		int indexParrent = getParentIndex(index);

		while (index != 0
			&&
			list_->at(index)->getPriority() < 
		    list_->at(indexParrent)->getPriority())
		{
			Utils::swap(
				list_->at(index),
				list_->at(indexParrent)
			);

			index = indexParrent;
			indexParrent = getParentIndex(index);
		}
	}

	template<typename T>
	T Heap<T>::pop()
	{
		//TODO 06: Heap
		//throw std::runtime_error("Heap<T>::pop: Not implemented yet.");

		if (size() > 0) {
			int indexLast = size() - 1;
			PriorityQueueItem<T>* item;

			if (0 != indexLast) {
				Utils::swap(
					list_->at(0),
					list_->at(indexLast)
				);

				item = list_->removeAt(indexLast);

				int index = 0;
				int indexSon = getGreaterSonIndex(index);

				while (index != -1
					&&
					list_->at(index)->getPriority() >
					list_->at(indexSon)->getPriority())
				{
					Utils::swap(
						list_->at(index),
						list_->at(indexSon)
					);

					index = indexSon;
					indexSon = getGreaterSonIndex(index);
				}
			}
			else {
				item = list_->removeAt(0);
			}
				T result = item->accessData();
				delete item;
				return result;
		}
		else {
			throw std::logic_error("Prazdna queue");
		}
	}

	template<typename T>
	inline int Heap<T>::getParentIndex(int index)
	{
		//TODO 06: Heap
		//throw std::runtime_error("Heap<T>::getParentIndex: Not implemented yet.");
		// return (index + 1) / 2 - 1;

		return (index - 1) / 2;
	}

	template<typename T>
	inline int Heap<T>::getGreaterSonIndex(int index)
	{
		//TODO 06: Heap
		//throw std::runtime_error("Heap<T>::getGreaterSonIndex: Not implemented yet.");

		int leftIndex = 2 * index + 1;
		int rightIndex = 2 * index + 2;
		size_t size = list_->size();

		if (leftIndex >= size) {
			return -1;
		}
		else {
			if (rightIndex >= size) {
				return leftIndex;
			}
			else {
				return PriorityQueueList<T>::list_->at(leftIndex)->getPriority() <
					PriorityQueueList<T>::list_->at(rightIndex)->getPriority() ? leftIndex : rightIndex;
			}
		}
	}

	template<typename T>
	inline int Heap<T>::indexOfPeek()
	{
		//TODO 06: Heap
		//throw std::runtime_error("Heap<T>::indexOfPeek: Not implemented yet.");

		return 0;
	}
}