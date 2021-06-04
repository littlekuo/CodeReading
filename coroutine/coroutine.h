#ifndef C_COROUTINE_H
#define C_COROUTINE_H

//几种状态
#define COROUTINE_DEAD 0
#define COROUTINE_READY 1
#define COROUTINE_RUNNING 2
#define COROUTINE_SUSPEND 3

struct schedule;

typedef void (*coroutine_func)(struct schedule *, void *ud);

//开启一个调度器
struct schedule * coroutine_open(void);

//关闭一个调度器
void coroutine_close(struct schedule *);

//创建一个新协程
int coroutine_new(struct schedule *, coroutine_func, void *ud);

//切换到对应协程中运行
void coroutine_resume(struct schedule *, int id);

//获取指定id的协程状态
int coroutine_status(struct schedule *, int id);

//
int coroutine_running(struct schedule *);

// 协程切出
void coroutine_yield(struct schedule *);

#endif
