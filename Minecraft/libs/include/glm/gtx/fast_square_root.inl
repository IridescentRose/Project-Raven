///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2013 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2006-01-04
// Updated : 2011-10-14
// Licence : This source is under MIT License
// File    : glm/gtx/fast_square_root.inl
///////////////////////////////////////////////////////////////////////////////////////////////////

namespace glm
{
	// fastSqrt
	template <typename genType>
	GLM_FUNC_QUALIFIER genType fastSqrt
	(
		genType const & x
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'fastSqrt' only accept floating-point input");

		return genType(1) / fastInverseSqrt(x);
	}

	VECTORIZE_VEC(fastSqrt)

	// fastInversesqrt
	template <typename genType>
	GLM_FUNC_QUALIFIER genType fastInverseSqrt
	(
		genType const & x
	)
	{
		return detail::fastInversesqrt<genType, uint>(x);
	}

	VECTORIZE_VEC(fastInverseSqrt)

	// fastLength
	template <typename genType>
	GLM_FUNC_QUALIFIER genType fastLength
	(
		genType const & x
	)
	{
		return abs(x);
	}

	template <typename valType, precision P>
	GLM_FUNC_QUALIFIER valType fastLength
	(
		detail::tvec2<valType, P> const & x
	)
	{
		valType sqr = x.x * x.x + x.y * x.y;
		return fastSqrt(sqr);
	}

	template <typename valType, precision P>
	GLM_FUNC_QUALIFIER valType fastLength
	(
		detail::tvec3<valType, P> const & x
	)
	{
		valType sqr = x.x * x.x + x.y * x.y + x.z * x.z;
		return fastSqrt(sqr);
	}

	template <typename valType, precision P>
	GLM_FUNC_QUALIFIER valType fastLength
	(
		detail::tvec4<valType, P> const & x
	)
	{
		valType sqr = x.x * x.x + x.y * x.y + x.z * x.z + x.w * x.w;
		return fastSqrt(sqr);
	}

	// fastDistance
	template <typename genType>
	GLM_FUNC_QUALIFIER genType fastDistance
	(
		genType const & x, 
		genType const & y
	)
	{
		return fastLength(y - x);
	}

	// fastNormalize
	template <typename genType>
	GLM_FUNC_QUALIFIER genType fastNormalize
	(
		genType const & x
	)
	{
		return x > genType(0) ? genType(1) : -genType(1);
	}

	template <typename valType, precision P>
	GLM_FUNC_QUALIFIER detail::tvec2<valType, P> fastNormalize
	(
		detail::tvec2<valType, P> const & x
	)
	{
		valType sqr = x.x * x.x + x.y * x.y;
		return x * fastInverseSqrt(sqr);
	}

	template <typename valType, precision P>
	GLM_FUNC_QUALIFIER detail::tvec3<valType, P> fastNormalize
	(
		detail::tvec3<valType, P> const & x
	)
	{
		valType sqr = x.x * x.x + x.y * x.y + x.z * x.z;
		return x * fastInverseSqrt(sqr);
	}

	template <typename valType, precision P>
	GLM_FUNC_QUALIFIER detail::tvec4<valType, P> fastNormalize
	(
		detail::tvec4<valType, P> const & x
	)
	{
		valType sqr = x.x * x.x + x.y * x.y + x.z * x.z + x.w * x.w;
		return x * fastInverseSqrt(sqr);
	}
}//namespace glm
