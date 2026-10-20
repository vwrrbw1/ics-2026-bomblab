#include "defuser.h"

#include <inttypes.h>
#include <stdio.h>

#define MAX_FIELDS 8

/*
 * 把 values 中的 count 个整数写成一行“空格分隔的无符号十进制整数”，存入 out。
 * 成功返回 0；count 为 0（还没有实现）、snprintf 出错或结果被截断时返回非零。
 */
static int write_answer(char *out, size_t cap, const uint32_t *values, size_t count) {
    size_t used = 0;
    for (size_t i = 0; i < count; ++i) {
        int size = snprintf(out + used, cap - used, "%s%" PRIu32, i ? " " : "", values[i]);
        if (size < 0 || (size_t)size >= cap - used) return 1;
        used += (size_t)size;
    }
    return count == 0;
}

int solve_phase_1(uint64_t challenge, char *out, size_t cap) {
uint32_t values[MAX_FIELDS] = {0};
    size_t count = 1; 

    uint32_t high = (uint32_t)(challenge >> 32);
    uint32_t mid  = (uint32_t)(challenge >> 16);
    uint32_t low  = (uint32_t)challenge;

    uint32_t ret1 = (mid ^ 0xb25b) + high * 4;

    uint32_t ret0 = (low + high * 2) ^ 0xfb18;

    uint32_t diff = ret0 - ret1;
    uint32_t final_ans = diff * 3 + 0x3174;

    values[0] = final_ans;
    
    return write_answer(out, cap, values, count);
}

int solve_phase_2(uint64_t challenge, char *out, size_t cap) {
 uint32_t values[MAX_FIELDS] = {0};
    size_t count = 6; 

    uint32_t t = (uint32_t)(challenge >> 20);
    t = t * 2;
    t = t & 0x1e;
    values[0] = t + 0x1f;

    uint32_t ecx = 20;
    uint32_t edx = 1;
    for (int i = 1; i < 6; i++) {
        uint32_t temp = (uint32_t)(challenge >> ecx);
        temp = temp & 0x3f;
        temp = temp + edx;
        temp = temp ^ values[i-1]; 
        temp = temp * 5;           
        values[i] = temp;
        
        ecx += 2;
        edx += 1;
    }

    return write_answer(out, cap, values, count);
}

int solve_phase_3(uint64_t challenge, char *out, size_t cap) {
    uint32_t values[MAX_FIELDS] = {0};
    size_t count = 2;

    uint32_t index = (uint32_t)(challenge & 7);
    values[0] = index;

    uint32_t high_part = (uint32_t)(challenge >> 32);
    uint32_t low_part = (uint32_t)(challenge >> 3);
    uint32_t mix = high_part ^ low_part;

    uint32_t val = 0;
    switch (index) {
        case 0: val = (2 * mix) ^ 0x427d; break;           
        case 1: val = (mix ^ 0x123e) + (mix >> 2); break;  
        case 2: val = (mix ^ 0x746e) + (mix >> 1); break;  
        case 3: val = 3 * mix + 0x6913; break;            
        case 4: val = (4 * mix) ^ 0x4a92; break;           
        case 5: val = 5 * mix + 0x3e2bf; break;            
        case 6: val = 3 * mix + 0x3115; break;            
        case 7: val = 5 * mix + 0xe1af; break;             
    }
    values[1] = val;

    return write_answer(out, cap, values, count);
}

static uint32_t p4_walk_recursive(uint32_t target, uint32_t low, uint32_t high, uint32_t key) {
    uint32_t mid = low + (high - low) / 2;
    
    if (mid == target) {
        return (target + 0x8e) ^ key;
    }
    
    uint32_t ebx = mid + key; 
    uint32_t ret;
    
    if (target < mid) {
        ret = p4_walk_recursive(target, low, mid - 1, key);
        ret = (ret * 3) ^ ebx;
        return ret ^ 0x1c;
    } else {
        ret = p4_walk_recursive(target, mid + 1, high, key);
        ret = (ret * 3) ^ ebx;
        return ret ^ 0x7;
    }
}

int solve_phase_4(uint64_t challenge, char *out, size_t cap) {
    uint32_t values[MAX_FIELDS] = {0};
    size_t count = 1; 

    uint32_t target = (uint32_t)(challenge & 0x7f);
    uint32_t low = 0;
    uint32_t high = 0x7f;
    uint32_t key = (uint32_t)(challenge >> 7) ^ (uint32_t)(challenge >> 32);

    values[0] = p4_walk_recursive(target, low, high, key);

    return write_answer(out, cap, values, count);
}


struct p5_Node {
    int next;
    uint32_t field_8;
    uint32_t field_12;
};


static struct p5_Node p5_nodes[] = {
    { 1, 0x42c, 0xed5 },
     { 11, 0x880, 0x67f4 },
     { 9, 0xb0d, 0xc147 },
     { -1, 0x104, 0xdb81 },
     { 8, 0x35c, 0x2ab9 },
     { 3, 0x613, 0x1bf },
     { 10, 0x538, 0x5bcc },
     { 4, 0x965, 0xddef },
     { 6, 0x712, 0x4c0f },
     { 5, 0x272, 0x6e0 },
     { 2, 0xa44, 0xdfa9 },
     { 7, 0x31, 0xb944 }
};

static int p5_heads[] = { 0, 1, 11, 7, 4, 8, 6, 10 };

static uint32_t p5_traverse_sim(uint64_t challenge, uint32_t *val2) {
    uint32_t index = (uint32_t)(challenge & 7);
    uint32_t loop_count = (uint32_t)((challenge >> 3) & 3);
    
    int node_idx = p5_heads[index];
    struct p5_Node *node = &p5_nodes[node_idx];
    
    uint32_t eax = ((uint32_t)(challenge >> 6) ^ (uint32_t)(challenge >> 32)) ^ 0x48e8;
    eax = (eax + node->field_12) * 5;
    *val2 = node->field_8;
    eax = eax ^ node->field_8;
    
    for (uint32_t i = 1; i <= loop_count; i++) {
        node = &p5_nodes[node->next];
        eax = (eax + node->field_12) * 5;
        *val2 = node->field_8;
        eax = eax ^ node->field_8;
    }
    return eax;
}

int solve_phase_5(uint64_t challenge, char *out, size_t cap) {
uint32_t values[MAX_FIELDS] = {0};
    size_t count = 2; 
    uint32_t val2 = 0;
    
    values[0] = p5_traverse_sim(challenge, &val2);
    values[1] = val2;
    
    return write_answer(out, cap, values, count);
}

static uint32_t ror32(uint32_t x, int n) {
    return (x >> n) | (x << (32 - n));
}
static uint32_t rol32(uint32_t x, int n) {
    return (x << n) | (x >> (32 - n));
}

static uint32_t p6_op_0(uint32_t x) { return (x + 0x51cf) ^ (x >> 1); }
static uint32_t p6_op_1(uint32_t x) { return (x * 8 + 0x1cc1) ^ (x * 5); }
static uint32_t p6_op_2(uint32_t x) { return (x ^ 0x414) + x * 4; }
static uint32_t p6_op_3(uint32_t x) { return ((x >> 1) ^ x) + 0x1d1f; }
static uint32_t p6_op_4(uint32_t x) { return ror32(x, 2); }
static uint32_t p6_op_5(uint32_t x) { return rol32(x, 5) ^ 0x9b59; }

static uint32_t p6_call_op(uint32_t index, uint32_t x) {
    switch (index) {
        case 0: return p6_op_1(x);
        case 1: return p6_op_1(x);
        case 2: return p6_op_2(x);
        case 3: return p6_op_3(x);
        case 4: return p6_op_4(x);
        case 5: return p6_op_0(x);
        case 6: return p6_op_5(x);
        case 7: return p6_op_4(x);
        default: return 0;
    }
}

int solve_phase_6(uint64_t challenge, char *out, size_t cap) {
uint32_t values[MAX_FIELDS] = {0};
    size_t count = 1; 

    uint32_t arg1 = (uint32_t)(challenge >> 6) ^ (uint32_t)(challenge >> 32);
    uint32_t index1 = (uint32_t)(challenge & 0x7);
    
    uint32_t ret1 = p6_call_op(index1, arg1);

    uint32_t arg2 = ret1 ^ 0x66fa;
    uint32_t index2 = (uint32_t)((challenge & 0x38) >> 3);
    
    uint32_t ret2 = p6_call_op(index2, arg2);

    values[0] = ret2 + 0xc3d8;

    return write_answer(out, cap, values, count);
}

int solve_secret(uint64_t challenge, uint64_t context, char *out, size_t cap) {
    uint32_t c_low = (uint32_t)challenge;
    uint32_t c_high = (uint32_t)(challenge >> 32);
    uint32_t c_mix = c_low ^ c_high;

    uint32_t ctx_low = (uint32_t)context;
    uint32_t ctx_high = (uint32_t)(context >> 32);
    uint32_t ctx_mix = ctx_low ^ ctx_high;

    uint32_t val1 = ctx_low & 0x3;
    uint32_t mix_arg = c_mix ^ ctx_mix;
    uint32_t mix_ret = ((mix_arg >> 7) | (mix_arg << 25)) ^ 0x86ac;

    uint32_t r9d = (val1 * 0x2f8d) ^ (uint32_t)(context >> 16);
    uint32_t val2 = mix_ret ^ r9d;

    uint32_t edx = ctx_mix + val1 + 0xa921 + (c_mix >> 7);
    uint32_t val3 = val2 ^ edx;

    int len = snprintf(out, cap, 
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOPEN %u %u %u", 
        val1, val2, val3);
        
    return (len < 0 || (size_t)len >= cap) ? 1 : 0;
}