#pragma once

#include "matrix.h"
#include "../vector/vector.h"
#include "../utils.h"
#include <stdexcept>

namespace structures
{
	/// <summary> Implementacia matice v suvislej pamati. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v matici. </typepram>
	template<typename T>
	class CoherentMatrix
		: public Matrix<T>
	{
	public:
		/// <summary>
		///	Konstruktor. Vytvori maticu o danom pocte riadkov a stlpcov.
		/// Polozky su inicializovane na "nulovu" hodnotu typu T.
		/// </summary>
		/// <param name="rowCount"> Pocet riadkov. </param>
		/// <param name="columnCount"> Pocet stlpcov. </param>
		CoherentMatrix(size_t rowCount, size_t columnCount);

		/// <summary> Inicializuje tuto maticu ako kopiu matice odovzdanej ako parameter. </summary>
		/// <param name = "other"> Odkaz na maticu, z ktorej sa prevezmu vlastnosti. </param>
		CoherentMatrix(CoherentMatrix& other);

		/// <summary> Destruktor. </summary>
		~CoherentMatrix();

		/// <summary>
		/// Ak je to mozne (parametrom je matica, ktora ma rovnake rozmery ako ako aktualna matica),
		/// tak skopiruje vlastnosti z matice odovzdanej ako parameter.
		/// Ak to nie je mozne, vyhodi sa vynimka.
		/// </summary>
		/// <param name = "other"> Odkaz na strukturu, z ktorej maju prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary>
		/// Ak je parametrom matica a obsah porovnavanych matic je rovnaky,
		/// tak vrati hodnotu true. V opacnom pripade vrati hodnotu false.
		/// </summary>
		/// <param name="other"> Odkaz na strukturu, s ktorou sa ma tato matica porovnat. </param>
		/// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
		bool equals(Structure& other) override;

		/// <summary> Pocet vsetkych prvkov v matici. </summary>
		/// <returns> Pocet prvkov v matici. </returns>
		size_t size() override;

		/// <summary> Vrati pocet riadkov v matici. </summary>
		/// <returns> Pocet riadkov matice. </returns>
		size_t getRowCount() override;

		/// <summary> Vrati pocet stlpcov matice. </summary>
		/// <returns> Pocet stlpcov matice. </returns>
		size_t getColumnCount() override;

		/// <summary> Vrati odkaz na prvok v danom riadku a stlpci. </summary>
		/// <param name="rowIndex"> Index riadku. </param>
		/// <param name="columnIndex"> Index stlpca. </param>
		/// <returns> Odkaz na prvok na danych indexoch. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index riadku alebo stlpca nepatri do matice. </exception>
		T& at(int rowIndex, int columnIndex) override;

	private:
		/// <summary>
		/// pocet prvkov v zozname
		/// </summary>
		size_t size_;

		/// <summary>
		/// Pole s datami
		/// </summary>
		Vector* vector_;

		/// <summary>
		/// pocet riadkov v matici
		/// </summary>
		size_t rowCount_;

		/// <summary>
		/// pocet stlpcov v matici
		/// </summary>
		size_t columnCount_;

	private:
		int mapFunction(int rIndex, int cIndex) const;
	};

	template<typename T>
	inline CoherentMatrix<T>::CoherentMatrix(size_t rowCount, size_t columnCount) :
		Matrix<T>(),
		rowCount_(rowCount),
		columnCount_(columnCount),
		size_(rowCount * columnCount),
		vector_(new Vector(rowCount * columnCount * sizeof(T)))
	{
	}

	template<typename T>
	inline CoherentMatrix<T>::CoherentMatrix(CoherentMatrix<T>& other) :
		Matrix<T>(), //vytvorim si maticu
		rowCount_(other.rowCount_), //zoberiem jej pocet riadkov
		columnCount_(other.columnCount_), //zoberiem jej pocet stlpcov
		size_(other.size_), //zoberiem jej stlpce * riadky
		vector_(new Vector(*other.vector_)) //a jej pole
	{
	}

	template<typename T>
	inline CoherentMatrix<T>::~CoherentMatrix()
	{
		//TODO Zadanie 1: CoherentMatrix
		//throw std::runtime_error("CoherentMatrix<T>::~CoherentMatrix: Not implemented yet.");

		// int hodnoty 0 delete array a dat nullptr 
		delete vector_;
		vector_ = nullptr;
		rowCount_ = 0;
		columnCount_ = 0;
		size_ = 0;
	}

	template<typename T>
	inline Structure& CoherentMatrix<T>::assign(Structure& other)
	{
		//TODO Zadanie 1: CoherentMatrix

		//ak neukazuju na rovnaku maticu tak pretypujem pomocou & lebo ak sa nepodari vrati vynimku
		if (this != &other) {
			CoherentMatrix<T>& otherMatrix = dynamic_cast<CoherentMatrix<T>&>(other);

			if (this->columnCount_ == otherMatrix.getColumnCount() && this->rowCount_ == otherMatrix.getRowCount()) {
				this->vector_->assign(*otherMatrix.vector_);
			}
			else {
				throw std::invalid_argument("Different row or column size");
			}
		}
		return *this;
	}

	template<typename T>
	inline bool CoherentMatrix<T>::equals(Structure& other)
	{
		//TODO Zadanie 1: CoherentMatrix
		//throw std::runtime_error("CoherentMatrix<T>::equals: Not implemented yet.");

		if (this == &other) {
			return true;
		}
		else {
			CoherentMatrix<T>* otherMatrix = dynamic_cast<CoherentMatrix<T>*>(&other);

			if (otherMatrix != nullptr && otherMatrix->getColumnCount() == this->columnCount_ && otherMatrix->getRowCount() == this->rowCount_) {
				return this->vector_->equals(*otherMatrix->vector_);
			}
			else {
				return false;
			}
		}
		return false;
	}

	template<typename T>
	inline size_t CoherentMatrix<T>::size()
	{
		//TODO Zadanie 1: CoherentMatrix
		//throw std::runtime_error("CoherentMatrix<T>::size: Not implemented yet.");

		return this->size_;
	}

	template<typename T>
	inline size_t CoherentMatrix<T>::getRowCount()
	{
		//TODO Zadanie 1: CoherentMatrix
		//throw std::runtime_error("CoherentMatrix<T>::getRowCount: Not implemented yet.");

		return this->rowCount_;
	}

	template<typename T>
	inline size_t CoherentMatrix<T>::getColumnCount()
	{
		//TODO Zadanie 1: CoherentMatrix
		//throw std::runtime_error("CoherentMatrix<T>::getColumnCount: Not implemented yet.");

		return this->columnCount_;
	}

	template<typename T>
	inline T& CoherentMatrix<T>::at(int rowIndex, int columnIndex)
	{
		//TODO Zadanie 1: CoherentMatrix
		//throw std::runtime_error("CoherentMatrix<T>::at: Not implemented yet.");
		
		return reinterpret_cast<T&>(vector_->at(mapFunction(rowIndex, columnIndex)));
	}

	template<typename T>
	inline int CoherentMatrix<T>::mapFunction(int rIndex, int cIndex) const 
	{

		Utils::rangeCheckExcept(rIndex, rowCount_, "Invalid Index of row");
		Utils::rangeCheckExcept(cIndex, columnCount_, "Invalid Index of column");

		return (rIndex * columnCount_ + cIndex) * sizeof(T);
	}
}