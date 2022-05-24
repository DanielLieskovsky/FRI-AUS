#pragma once

#include "table.h"
#include "../list/list.h"
#include "../tree/binary_tree.h"
#include <stdexcept>

namespace structures
{

	/// <summary> Binarny vyhladavaci strom. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class BinarySearchTree : public Table<K, T>
	{
	public:
		typedef typename BinaryTreeNode<TableItem<K, T>*> BSTTreeNode;
	public:
		/// <summary> Konstruktor. </summary>
		BinarySearchTree();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> BinarySearchTree, z ktoreho sa prevezmu vlastnosti. </param>
		BinarySearchTree(BinarySearchTree<K, T>& other);

		/// <summary> Destruktor. </summary>
		~BinarySearchTree();

		/// <summary> Vrati pocet prvkov v tabulke. </summary>
		/// <returns> Pocet prvkov v tabulke. </returns>
		size_t size() override;

		/// <summary> Priradenie struktury. </summary>
		/// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Porovnanie struktur. </summary>
		/// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
		/// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
		bool equals(Structure& other) override;

		/// <summary> Vrati adresou data s danym klucom. </summary>
		/// <param name = "key"> Kluc dat. </param>
		/// <returns> Adresa dat s danym klucom. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak kluc nepatri do tabulky. </exception>
		T& find(const K& key) override;

		/// <summary> Vlozi data s danym klucom do tabulky. </summary>
		/// <param name = "key"> Kluc vkladanych dat. </param>
		/// <param name = "data"> Vkladane data. </param>
		/// <exception cref="std::logic_error"> Vyhodena, ak tabulka uz obsahuje data s takymto klucom. </exception>
		void insert(const K& key, const T& data) override;

		/// <summary> Odstrani z tabulky prvok s danym klucom. </summary>
		/// <param name = "key"> Kluc prvku. </param>
		/// <returns> Odstranene data. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak tabulka neobsahuje data s takymto klucom. </exception>
		T remove(const K& key) override;

		/// <summary> Bezpecne ziska data s danym klucom. </summary>
		/// <param name = "key"> Kluc dat. </param>
		/// <param name = "data"> Najdene data (vystupny parameter). </param>
		/// <returns> true, ak sa podarilo najst a naplnit data s danym klucom, false inak. </returns>
		bool tryFind(const K& key, T& data) override;

		/// <summary> Zisti, ci tabulka obsahuje data s danym klucom. </summary>
		/// <param name = "key"> Kluc dat. </param>
		/// <returns> true, tabulka obsahuje dany kluc, false inak. </returns>
		bool containsKey(const K& key) override;

		/// <summary> Vymaze tabulku. </summary>
		void clear() override;

		/// <summary> Vrati skutocny iterator na zaciatok struktury </summary>
		/// <returns> Iterator na zaciatok struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<TableItem<K, T>*>* getBeginIterator() override;

		/// <summary> Vrati skutocny iterator na koniec struktury </summary>
		/// <returns> Iterator na koniec struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<TableItem<K, T>*>* getEndIterator() override;

	protected:
		/// <summary> Najde vrchol binarneho vyhladavacieho stromu s danym klucom. </summary>
		/// <param name = "key"> Hladany kluc. </param>
		/// <param name = "found"> Vystupny parameter, ktory indikuje, ci sa kluc nasiel. </param>
		/// <returns> Vrchol binarneho vyhladavacieho stromu s danym klucom. Ak sa kluc v tabulke nenachadza, vrati otca, ktoreho by mal mat vrchol s takym klucom. </returns>
		typename BSTTreeNode* findBSTNode(K key, bool& found);

	protected:
		/// <summary> Binarny strom s datami. </summary>
		BinaryTree<TableItem<K, T>*>* binaryTree_;
		/// <summary> Pocet prvkov v binarnom vyhladavacom strome. </summary>
		size_t size_;

		/// <summary> Vlozi vrchol do stromu tak, aby nedoslo k naruseniu usporiadania BST. </summary>
		/// <param name = "node"> Vrchol stromu, ktory ma byt vlozeny. </param>
		/// <returns> true, ak sa podarilo vrchol vlozit (teda v strome nie je vrchol s rovnakym klucom), false inak. </returns>
		bool tryToInsertNode(BSTTreeNode* node);

		/// <summary> Bezpecne vyjme zo stromu vrchol stromu tak, aby nedoslo k naruseniu usporiadania BST. </summary>
		/// <param name = "node"> Vrchol stromu, ktory ma byt vyjmuty. </param>
		/// <remarks> Vrchol nebude zruseny, iba odstraneny zo stromu a ziadne vrcholy nebudu ukazovat na neho a ani on nebude ukazovat na ziadne ine vrcholy. </remarks>
		void extractNode(BSTTreeNode* node);
	};

	template<typename K, typename T>
	inline BinarySearchTree<K, T>::BinarySearchTree() :
		Table<K, T>(),
		binaryTree_(new BinaryTree<TableItem<K, T>*>()),
		size_(0)
	{
	}

	template<typename K, typename T>
	inline BinarySearchTree<K, T>::BinarySearchTree(BinarySearchTree<K, T>& other) :
		BinarySearchTree()
	{
		assign(other);
	}

	template<typename K, typename T>
	inline BinarySearchTree<K, T>::~BinarySearchTree()
	{
		clear();
		delete binaryTree_;
		binaryTree_ = nullptr;
	}

	template<typename K, typename T>
	inline size_t BinarySearchTree<K, T>::size()
	{
		//TODO 10: BinarySearchTree
		/*throw std::runtime_error("BinarySearchTree<K, T>::size: Not implemented yet.");*/

		return size_;
	}

	template<typename K, typename T>
	inline Structure& BinarySearchTree<K, T>::assign(Structure& other)
	{
		//TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::assign: Not implemented yet.");

		if (this != &other)
		{
			BinarySearchTree<K, T>& otherBST = dynamic_cast<BinarySearchTree<K, T>&>(other);
			clear();

			auto iteratorB = new Tree<TableItem<K, T>*>::PreOrderTreeIterator(otherBST.binaryTree_->getRoot());
			auto iteratorE = new Tree<TableItem<K, T>*>::PreOrderTreeIterator(nullptr);

			while (*(iteratorB) != *(iteratorE))
			{
				TableItem<K, T>* item = *(*iteratorB);
				insert(item->getKey(), item->accessData());
				++* (iteratorB);
			}
			delete iteratorB;
			delete iteratorE;
		}
		return *this;
	}

	template<typename K, typename T>
	inline bool BinarySearchTree<K, T>::equals(Structure& other)
	{
		return Table<K, T>::equalsTable(dynamic_cast<BinarySearchTree<K, T>*>(&other));
	}

	template<typename K, typename T>
	inline T& BinarySearchTree<K, T>::find(const K& key)
	{
		//TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::find: Not implemented yet.");
		bool found = false;
		auto node = findBSTNode(key, found);
		if (found)
		{
			return node->accessData()->accessData();
		}
		else
		{
			throw std::logic_error("Chyba");
		}
	}

	template<typename K, typename T>
	inline void BinarySearchTree<K, T>::insert(const K& key, const T& data)
	{
		//TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::insert: Not implemented yet.");

		TableItem<K, T>* item = new TableItem<K, T>(key, data);
		BSTTreeNode* node = new BSTTreeNode(item);

		if (!tryToInsertNode(node))
		{
			delete item;
			delete node;
			throw std::logic_error("Key uz existuje");
		}
	}

	template<typename K, typename T>
	inline T BinarySearchTree<K, T>::remove(const K& key)
	{
		//TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::remove: Not implemented yet.");

		bool found = false;

		BSTTreeNode* hladany = this->findBSTNode(key, found);

		if (found == true)
		{
			this->extractNode(hladany);
			auto data = hladany->accessData()->accessData();
			delete hladany->accessData();
			delete hladany;
			size_--;
			return data;
		} 
		else
		{
			throw std::logic_error("Neexistujuci prvok");
		}
	}

	template<typename K, typename T>
	inline bool BinarySearchTree<K, T>::tryFind(const K& key, T& data)
	{
		//TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::tryFind: Not implemented yet.");

		bool found = false;
		auto node = findBSTNode(key, found);
		if (found)
		{
			data =  node->accessData()->accessData();
			return true;
		}
		else
		{
			return false;
		}
	}

	template<typename K, typename T>
	inline bool BinarySearchTree<K, T>::containsKey(const K& key)
	{
		//TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::containsKey: Not implemented yet.");

		bool found = false;
		findBSTNode(key, found);
		return found;
	}

	template<typename K, typename T>
	inline void BinarySearchTree<K, T>::clear()
	{
		////TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::clear: Not implemented yet.");

		for (auto item : *binaryTree_)
		{
			delete item;
		}
		
		binaryTree_->clear();
		size_ = 0;
	}

	template<typename K, typename T>
	inline Iterator<TableItem<K, T>*>* BinarySearchTree<K, T>::getBeginIterator()
	{
		//TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::getBeginIterator: Not implemented yet.");

		return new BinaryTree<TableItem<K, T>*>::InOrderTreeIterator(binaryTree_->getRoot());
	}

	template<typename K, typename T>
	inline Iterator<TableItem<K, T>*>* BinarySearchTree<K, T>::getEndIterator()
	{
		//TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::getEndIterator: Not implemented yet.");

		return new BinaryTree<TableItem<K, T>*>::InOrderTreeIterator(nullptr);
	}

	template<typename K, typename T>
	inline typename BinarySearchTree<K, T>::BSTTreeNode* BinarySearchTree<K, T>::findBSTNode(K key, bool& found)
	{
		//TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::findBSTNode: Not implemented yet.");

		found = false;
		BSTTreeNode* poslednyVrchol = dynamic_cast<BSTTreeNode*>(binaryTree_->getRoot());
		if (binaryTree_->getRoot() == nullptr) //poslednyVrchol ==nullptr
		{
			return nullptr;
		}
		else
		{
			while (poslednyVrchol->accessData()->getKey() != key)
			{
				if (poslednyVrchol->accessData()->getKey() > key)
				{
					if (poslednyVrchol->hasLeftSon())
					{
						poslednyVrchol = poslednyVrchol->getLeftSon();
					}
					else
					{
						return poslednyVrchol;
					}
				}
				else
				{
					if (poslednyVrchol->hasRightSon())
					{
						poslednyVrchol = poslednyVrchol->getRightSon();
					}
					else
					{
						return poslednyVrchol;
					}
				}

			}
			found = true;
			return poslednyVrchol;
		}
	}

	template<typename K, typename T>
	inline bool BinarySearchTree<K, T>::tryToInsertNode(BSTTreeNode* node)
	{
		//TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::tryToInsertNode: Not implemented yet.");

		bool found = false;
		auto parent = findBSTNode(node->accessData()->getKey(), found);

		if (!found)
		{
			if (parent == nullptr)
			{
				binaryTree_->replaceRoot(node);
			}
			else if (node->accessData()->getKey() < parent->accessData()->getKey())
			{
				parent->setLeftSon(node);
			}
			else
			{
				parent->setRightSon(node);
			}
			size_++;
			return true;
		}
		else
		{
			return false;
		}
	}

	template<typename K, typename T>
	inline void BinarySearchTree<K, T>::extractNode(BSTTreeNode* node)
	{
		////TODO 10: BinarySearchTree
		//throw std::runtime_error("BinarySearchTree<K, T>::extractNode: Not implemented yet.");

		//nema ani 1 syna
		if (node->hasLeftSon() == false && node->hasRightSon() == false)
		{
			BSTTreeNode* otec = node->getParent();
			bool jeLavy = false;

			if (otec != nullptr) {
				if (node->isLeftSon())
				{
					jeLavy = true;
				}
			}

			if (jeLavy && otec != nullptr)
			{
				otec->changeLeftSon(nullptr);
			}
			else if (!jeLavy && otec != nullptr)
			{
				otec->changeRightSon(nullptr);
			}
			else if (node->degree() == 0)
			{
				binaryTree_->replaceRoot(nullptr);
			}
		}
		//ma len laveho syna
		else if (node->hasLeftSon() && !node->hasRightSon())
		{
			BSTTreeNode* otec = node->getParent();
			bool jeLavy = false;

			if (otec != nullptr) {
				if (node->isLeftSon())
				{
					jeLavy = true;
				}
			}

			if (jeLavy && otec != nullptr)
			{
				//v node nastavil na nullptr syna a tomu synovi nastavil nullptr
				otec->changeLeftSon(node->changeLeftSon(nullptr));
			}
			else if (!jeLavy && otec != nullptr)
			{
				otec->changeRightSon(node->changeLeftSon(nullptr));
			}
			else if (otec == nullptr)
			{
				binaryTree_->replaceRoot(node->changeLeftSon(nullptr));
			}
		}
		//ma len praveho
		else if (!node->hasLeftSon() && node->hasRightSon())
		{
			BSTTreeNode* otec = node->getParent();
			bool jeLavy = false;

			if (otec != nullptr) {
				if (node->isLeftSon())
				{
					jeLavy = true;
				}
			}

			if (jeLavy && otec != nullptr)
			{
				otec->changeLeftSon(node->changeRightSon(nullptr));
			}
			else if (!jeLavy && otec != nullptr)
			{
				otec->changeRightSon(node->changeRightSon(nullptr));
			}
			else if (otec == nullptr)
			{
				binaryTree_->replaceRoot(node->changeRightSon(nullptr));
			}
		}
		//ma oboch
		else if (node->hasLeftSon() && node->hasRightSon())
		{
			BSTTreeNode* pom = node;
			BSTTreeNode* otec = node->getParent();

			pom = pom->getRightSon();

			while (pom->hasLeftSon())
			{
				pom = pom->getLeftSon();
			}

			this->extractNode(pom);

			//ak nie je koren odstranovany
			if (otec != nullptr) {
				pom->changeLeftSon(node->changeLeftSon(nullptr));
				pom->changeRightSon(node->changeRightSon(nullptr));

				if (node->isLeftSon()) {
					node->getParent()->changeLeftSon(pom);
				}
				else
				{
					node->getParent()->changeRightSon(pom);
				}
			}
			//odstranovany koren s viacerymi urovanmi
			else if (node->getParent() == nullptr)
			{
				pom->changeLeftSon(node->changeLeftSon(nullptr));
				pom->changeRightSon(node->changeRightSon(nullptr));

				binaryTree_->replaceRoot(pom);
			}
		}
	}

}