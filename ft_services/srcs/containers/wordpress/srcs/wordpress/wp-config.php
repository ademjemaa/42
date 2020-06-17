<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );
define('WP_HOME', 'http://192.168.99.145:5050/');
define('WP_SITEURL', 'http://192.168.99.145:5050/');

/** MySQL database username */
define( 'DB_USER', 'adem123' );

/** MySQL database password */
define( 'DB_PASSWORD', 'adem123' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql-service' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '&c7F}QUj/kK{sqTDh]9sQY?[Eck#UjS9qNYp)=,GeN75]p_N_ VGwgJ`XYN1Yg``' );
define( 'SECURE_AUTH_KEY',  'OW[KIQZ4J@8R!7_#&m3CvLFs{e8`R28wg}U@nWh5th.O(),C|yt0E;@r7]=={B&`' );
define( 'LOGGED_IN_KEY',    'vI9Bm_EN<6Cu&}(f`I8:S KF~P[;~NMqB#iY6%C<E4 7QtMK~ u=DN[-eKa&pC_C' );
define( 'NONCE_KEY',        ':#j}Q4h- ;z!NGQMy#N@R[-r~nnc*jAc2WC[MG~AkDerJ`u+]=(fIHcr[p%!jx:M' );
define( 'AUTH_SALT',        '/Kd1<z4nSp5-H|XI-Q3e,@`oY`ZyptwEO(}Al&ao1KvBdc:TEhd6d1xB` +0n[Fw' );
define( 'SECURE_AUTH_SALT', '5L:~d`a:xo=5154s39n+kJ~;U;o{Ev~;&c|PO:O]WfDs]s|?B`o~B75^G=3+3qx]' );
define( 'LOGGED_IN_SALT',   'j[Ib,BgBLx!9!YQ_DP.rvux>*T0:M(m+7-1k};`|,f7i*jvlHo~X)yt,_W>QpTIp' );
define( 'NONCE_SALT',       'ODF@`7S@e epw`(b,=fteG&VH,<)+o9f%ik.a^KmfV4(m7hm6KM-J]{B(clZbp|v' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
