#pragma once
#include <math.h>
#include "util_move.h"

namespace util
{
template <typename D>
class vector2
{
	D x_;
	D y_;
	
public:
	vector2(D x, D y):
	x_(util::move(x)),
	y_(util::move(y))
	{}
	
	vector2():
	x_(0),
	y_(0)
	{}
	
	D x() const
	{
		return x_;
	}
	
	D y() const
	{
		return y_;
	}
	
	/**
	 * Setter para x.
	 */
	void x(D x)
	{
		x_ = util::move(x);
	}
	
	/**
	 * Setter para y.
	 */
	void y(D y)
	{
		y_ = util::move(y);
	}
	
	/**
	 * Devuelve la longitud del vector.
	 */
	D distance() const
	{
		return sqrt(x_*x_ + y_*y_);
	}
	
	/**
	 * Devuelve la longitud al cuadrado del vector
	 */
	D distance_sq() const
	{
		return x_*x_ + y_*y_;
	}
};
typedef vector2<float> vec2;

template <typename D>
vector2<D>& operator+=(vector2<D>& lhs, const vector2<D>& rhs)
{
	lhs.x(lhs.x() + rhs.x());
	lhs.y(lhs.y() + rhs.y());
	return lhs;
}

template <typename D>
vector2<D> operator+(vector2<D> lhs, const vector2<D> rhs)
{
	return lhs += rhs;
}

template <typename D>
vector2<D>& operator-=(vector2<D>& lhs, const vector2<D>& rhs)
{
	lhs.x(lhs.x() - rhs.x());
	lhs.y(lhs.y() - rhs.y());
	return lhs;
}

template <typename D>
vector2<D> operator-(vector2<D> lhs, const vector2<D> rhs)
{
	return lhs -= rhs;
}

template <typename D>
vector2<D>& operator*=(vector2<D>& lhs, D n)
{
	lhs.x(lhs.x() * n);
	lhs.y(lhs.y() * n);
	return lhs;
}

template <typename D>
vector2<D> operator*(vector2<D> lhs, D n)
{
	return lhs *= n;
}

template <typename D>
vector2<D>& operator/=(vector2<D>& lhs, D n)
{
	lhs.x(lhs.x() / n);
	lhs.y(lhs.y() / n);
	return lhs;
}

template <typename D>
vector2<D> operator/(vector2<D> lhs, D n)
{
	return lhs /= n;
}
}