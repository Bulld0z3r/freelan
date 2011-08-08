/*
 * libasiotap - A portable TAP adapter extension for Boost::ASIO.
 * Copyright (C) 2010-2011 Julien Kauffmann <julien.kauffmann@freelan.org>
 *
 * This file is part of libasiotap.
 *
 * libasiotap is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * libasiotap is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 *
 * If you intend to use libasiotap in a commercial software, please
 * contact me : we may arrange this for a small fee or no fee at all,
 * depending on the nature of your project.
 */

/**
 * \file bootp_helper.hpp
 * \author Julien KAUFFMANN <julien.kauffmann@freelan.org>
 * \brief A BOOTP helper class.
 */

#ifndef ASIOTAP_OSI_BOOTP_HELPER_HPP
#define ASIOTAP_OSI_BOOTP_HELPER_HPP

#include "helper.hpp"
#include "bootp_frame.hpp"

namespace asiotap
{
	namespace osi
	{
		/**
		 * \brief The const bootp helper class.
		 */
		typedef const_helper<bootp_frame> const_bootp_helper;

		/**
		 * \brief The mutable bootp helper class.
		 */
		typedef mutable_helper<bootp_frame> mutable_bootp_helper;

		/**
		 * \brief Check if a frame is valid.
		 * \param frame The frame.
		 * \return true on success.
		 */
		bool check_frame(const_bootp_helper frame);

		/**
		 * \brief The const bootp helper implementation class.
		 */
		template <>
		class _const_helper_impl<bootp_frame> : public _base_const_helper<bootp_frame>
		{
			public:

				/*
				 * \brief Get the payload buffer.
				 * \return The payload.
				 */
				boost::asio::const_buffer payload() const;

			protected:

				/**
				 * \brief Create a helper from a frame type structure.
				 * \param buf The buffer to refer to.
				 */
				_const_helper_impl(boost::asio::const_buffer buf);
		};

		/**
		 * \brief The mutable udp helper implementation class.
		 */
		template <>
		class _mutable_helper_impl<bootp_frame> : public _base_mutable_helper<bootp_frame>
		{
			public:

				/**
				 * \brief Get the payload buffer.
				 * \return The payload.
				 */
				boost::asio::mutable_buffer payload() const;

			protected:

				/**
				 * \brief Create a helper from a frame type structure.
				 * \param buf The buffer to refer to.
				 */
				_mutable_helper_impl(boost::asio::mutable_buffer buf);
		};

		inline bool check_frame(const_bootp_helper frame)
		{
			(void)frame;

			return true;
		}

		inline boost::asio::const_buffer _const_helper_impl<bootp_frame>::payload() const
		{
			return buffer() + sizeof(frame_type);
		}

		inline _const_helper_impl<bootp_frame>::_const_helper_impl(boost::asio::const_buffer buf) :
			_base_const_helper<bootp_frame>(buf)
		{
		}

		inline boost::asio::mutable_buffer _mutable_helper_impl<bootp_frame>::payload() const
		{
			return buffer() + sizeof(frame_type);
		}
		
		inline _mutable_helper_impl<bootp_frame>::_mutable_helper_impl(boost::asio::mutable_buffer buf) :
			_base_mutable_helper<bootp_frame>(buf)
		{
		}
	}
}

#endif /* ASIOTAP_OSI_BOOTP_HELPER_HPP */

