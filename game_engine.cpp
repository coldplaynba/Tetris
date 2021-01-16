#include "game_engine.h"

game_engine::game_engine(int main_x, int main_y, int next_x, int next_y)
    : main_bd(main_x, main_y, MAIN_BOARD_HEIGHT, MAIN_BOARD_WIDTH),
      next_bd(next_x, next_y, NEXT_BOARD_HEIGHT, NEXT_BOARD_WIDTH)
{
    QTime time = QTime::currentTime();
    int seed = time.second() * TIME_SCALAR + time.msec();
    m_ishape = 0;
    move_down_ok = true;
    tracked_shape = NULL;
    qsrand(seed);
}
//设置形状颜色
int game_engine::set_shape_color(int _color)
{
    int color = tracked_shape->get_color();
    //遍历形状
    for(int i = 0; i < NUM_OF_CELLS; i++)
    {
        //取出方格中的位置坐标
        QPoint tmp = tracked_shape->get_a_cell(i).get_location();
        //得到第几列第几行
        int r = tmp.x();
        int c = tmp.y();
        //染色
        main_bd.get_a_cell(r, c).set_color(_color);
    }

    return color;
}
//将产生的形状放在下一个棋盘上
void game_engine::next_place_shape()
{
    int ishape=qrand()% NUM_OF_SHAPES;//在7种形状中产生一个随机数
    //将ishape放在nex_bd棋盘上，置于棋盘中间
    place_shape(next_bd,HRZ_CENTER,VRTX_CENTER,ishape);
    m_ishape=ishape;//记录要产生的形状，传递给主棋盘
}
//将产生的形状放在主棋盘上
void game_engine::main_place_shape()
{
    move_down_ok=true;

    //将上一个形状删掉
    if(tracked_shape !=NULL)
    {
        delete  tracked_shape;
        tracked_shape=NULL;
    }
    //将下一个要产生的形状放在主棋盘上，置顶居中，将返回值返回存储起来
    tracked_shape=place_shape(main_bd,HRZ_CENTER,VRTX_START,m_ishape);
}

//把形状放在棋盘上,并将其染色
//四个形参 ：1——在那个棋盘放这个形状，2/3——形状的位置(在棋盘哪个位置)，4放的是哪个形状
shape * game_engine::place_shape(board &bd, int h, int v, int num)
{
   shape * _shape= NULL;

   switch (num)
   {
   case L_SHAPE://如果是l_shape
   {
       //获得哪个形状在哪个位置
       const QPoint point =bd.get_start_location(L_SHAPE,h,v);
       //获取第一个方格
       cell& tmp = bd.get_a_cell(point.x(), point.y());
       //构建形状，将形状进行染色
       _shape = new lshape(tmp, bd);
       break;
   }
   case O_SHAPE://如果是o_shape
   {
       //获得哪个形状在哪个位置
       const QPoint point =bd.get_start_location(O_SHAPE,h,v);
       //获取方格
       cell& tmp = bd.get_a_cell(point.x(), point.y());
       //构建形状，将形状进行染色
       _shape = new oshape(tmp, bd);
       break;
   }
   case I_SHAPE://如果是i_shape
   {
       //获得哪个形状在哪个位置
       const QPoint point =bd.get_start_location(I_SHAPE,h,v);
       //获取方格
       cell& tmp = bd.get_a_cell(point.x(), point.y());
       //构建形状，将形状进行染色
       _shape = new ishape(tmp, bd);
       break;
   }
   case J_SHAPE://如果是j_shape
   {
       //获得哪个形状在哪个位置
       const QPoint point =bd.get_start_location(J_SHAPE,h,v);
       //获取方格
       cell& tmp = bd.get_a_cell(point.x(), point.y());
       //构建形状，将形状进行染色
       _shape=new jshape(tmp,bd);
       break;
   }
   case S_SHAPE://如果是s_shape
   {
       //获得哪个形状在哪个位置
       const QPoint point =bd.get_start_location(S_SHAPE,h,v);
       //获取方格
       cell& tmp = bd.get_a_cell(point.x(), point.y());
       //构建形状，将形状进行染色
       _shape = new sshape(tmp, bd);
       break;
   }
   case T_SHAPE://如果是t_shape
   {
       //获得哪个形状在哪个位置
       const QPoint point =bd.get_start_location(T_SHAPE,h,v);
       //获取方格
       cell& tmp = bd.get_a_cell(point.x(), point.y());
       //构建形状，将形状进行染色
       _shape = new tshape(tmp, bd);
       break;
   }
   case Z_SHAPE://如果是z_shape
   {
       //获得哪个形状在哪个位置
       const QPoint point =bd.get_start_location(Z_SHAPE,h,v);
       //获取方格
       cell& tmp = bd.get_a_cell(point.x(), point.y());
       //构建形状，将形状进行染色
       _shape = new zshape(tmp, bd);
       break;
   }
   default:
       break;
   }
   return _shape;
}
//向下移动
void game_engine::move_down()
{
    //判断能否移动
    bool moveable=is_moveable(DOWN,NO_MOVE,true);
    //如果能移动,向下移动
    if(moveable)
    {
        move(DOWN,NO_MOVE);
    }
}
//向左移
void game_engine::move_left()
{
    //判断能否移动
    bool moveable=is_moveable(NO_MOVE,LEFT,true);
    //如果能移动,向左移动
    if(moveable)
    {
        move(NO_MOVE,LEFT);
    }
}
//向右移
void game_engine::move_right()
{
    //判断能否移动
    bool moveable=is_moveable(NO_MOVE,RIGHT,true);
    //如果能移动,向右移动
    if(moveable)
    {
        move(NO_MOVE,RIGHT);
    }
}

//是否能够移动
bool game_engine::is_moveable(int up_down, int left_right, bool is_move_down)
{
    //往左往右移动判断，为true可以移动
    bool move_able=false;
    int color=NO_COLOR;

    //擦除所有方格颜色，存储原来方格颜色到color中
    for(int i=0;i<NUM_OF_CELLS;i++)
    {
        //获取这个形状的方格
        cell & tmp= tracked_shape->get_a_cell(i);
        //获取原来形状的颜色存储到color中
        color=main_bd.get_cell_color(tmp);
        //擦除所有方格颜色
        main_bd.set_cell_color(tmp,NO_COLOR);
    }

    //判断能否移动：能否下移，能否左右移动，下方是否已有形状
    for(int i=0;i<NUM_OF_CELLS;i++)
    {
        //获取该形状方格的几行（x）几列（y）
        int r=tracked_shape->get_a_cell(i).get_location().x();
        int c=tracked_shape->get_a_cell(i).get_location().y();

        //上下左右移动
        r+=up_down;
        c+=left_right;
        //判断是否触底且到达两边,如果没有move_able为true
        if(r>0&&r<MAIN_BOARD_HEIGHT && c>=0 && c<MAIN_BOARD_WIDTH && main_bd.get_a_cell(r,c).get_color()== NO_COLOR )
        {
            move_able = true;
        }
        else
        {
            //已到达两边或已触底；判断是否触底或下面有无图形（有图形会有颜色）
            if((r>=MAIN_BOARD_HEIGHT||main_bd.get_a_cell(r,c).get_color()!=NO_COLOR)&& is_move_down)
            {
                //无法再往下移动了
                move_down_ok=false;
            }

            move_able=false;
            break;
        }
    }
    //如果不能移动了。再加上原来的颜色
    if(!move_able)
    {
        for(int i=0;i<NUM_OF_CELLS;i++)
        {
            cell &tmp=tracked_shape->get_a_cell(i);
            main_bd.set_cell_color(tmp,color);
        }
    }
    return move_able;
}

//移动函数
void game_engine::move(int up_down, int left_right)
{
    for(int i=0;i<NUM_OF_CELLS;i++)
    {
        //获得当前方格
        cell &tmp=tracked_shape->get_a_cell(i);
        //获取几行几列
        int r = tmp.get_location().x();
        int y=tmp.get_location().y();
        //几行几列加上移动方块数
        r+=up_down;
        y+=left_right;

        //将方格移动后的位置记录下来
        cell &pass =main_bd.get_a_cell(r,y);
        //设置tracked_shape形状中的方格为移动后的方格
        tracked_shape->set_a_cell(i,pass);
        //染色
        main_bd.set_cell_color(pass,tracked_shape->get_color());

    }
}
//旋转函数
void game_engine::rotate()
{
   //去除原有形状颜色
    set_shape_color(NO_COLOR);
    //进行旋转
    tracked_shape->rotate();
    //再上色
    set_shape_color(tracked_shape->get_color());
}

void game_engine::clear_rows()
{
    traverse_rows();
}

int game_engine::num_rows_cld()
{
    int num = 0;

    traverse_rows(&num);

    return num;
}

void game_engine::traverse_rows(int* cld_rows)
{
    for(int i = MAIN_BOARD_HEIGHT - BIAS; i >= 0; i--)
    {
        if(main_bd.is_full(i))
        {
            if(cld_rows == NULL)
            {
                main_bd.clear_row(i);
            }
            else
            {
                ++*cld_rows;
            }
        }
    }
}

int game_engine::compute_score()
{
    int num = num_rows_cld();

    return num * num;
}

void game_engine::rows_move_down()
{
    int pointer_empty = MAIN_BOARD_HEIGHT - BIAS;
    int pointer_something = pointer_empty;

    for(int i = pointer_empty; i >= 0; i--)
    {
        if(main_bd.is_empty(i))
        {
            pointer_something = i - BIAS;

            for(int j = pointer_something; j >=0; j--)
            {
                if(main_bd.is_something(j))
                {
                    main_bd.row_cut_paste(j, i);
                    break;
                }
            }
        }
    }
}

game_engine::~game_engine()
{

}












