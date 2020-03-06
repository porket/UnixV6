/*
 * Used to dissect integer device code
 * into major (driver designation) and
 * minor (driver parameter) parts.
 */
struct
{
	char	d_minor;
	char	d_major;
};

/*
 * Declaration of block device
 * switch. Each entry (row) is
 * the only link between the
 * main unix code and the driver.
 * The initialization of the
 * device switches is in the
 * file conf.c.
 */
/*
 * 描述同一类设备的操作类型及驱动程序入口
 * 每类设备对应一张bdevsw表（同类设备共享）
 */
struct	bdevsw
{
	int	(*d_open)();   /*指向该设备的open函数*/
	int	(*d_close)();  /*指向该设备的close函数*/
	int	(*d_strategy)();
	int	*d_tab;  /*指向该设备的 struct devtab */
} bdevsw[];

/*
 * Nblkdev is the number of entries
 * (rows) in the block switch. It is
 * set in binit/bio.c by making
 * a pass over the switch.
 * Used in bounds checking on major
 * device numbers.
 */
int	nblkdev;

/*
 * Character device switch.
 */
struct	cdevsw
{
	int	(*d_open)();
	int	(*d_close)();
	int	(*d_read)();
	int	(*d_write)();
	int	(*d_sgtty)();
} cdevsw[];

/*
 * Number of character switch entries.
 * Set by cinit/tty.c
 */
int	nchrdev;
