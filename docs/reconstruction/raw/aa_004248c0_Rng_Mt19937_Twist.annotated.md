# Annotated low-level: `aa_004248c0` Rng_Mt19937_Twist

| Field | Value |
|---|---|
| Stable ID | `aa_004248c0` |
| VA | `0x004248c0` |
| Body | `0x004248c0`–`0x00424965` |
| Canonical name | `Rng_Mt19937_Twist` |
| Prior / alias | `FUN_004248c0`; `Named_CalleeOf_Named_CalleeOf_CVOGReaction_RandomUnitScalar_004248c0` |
| System | RNG / MT19937 state (global skills / reaction / misc consumers) |
| Date | 2026-07-29 (W18-K OWN-ONLY dual) |
| Tools | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete` (no `disassemble_bytes`) |

---

## Purpose

**Mersenne Twister MT19937 twist / state regeneration** over an in-object `uint32[624]` state array.

- State base pointer arrives in **ESI** (callers set ESI before `CALL`; leaf uses `unaff_ESI` in decompiler).
- Classic parameters:
  - **N** = `0x270` = **624**
  - **M** = `0x18d` = **397**
  - First loop count **N−M** = `0xe3` = **227**
  - Second loop count **M−1** = `0x18c` = **396**
  - Final wrap element uses `mt[0]`
  - **MATRIX_A** = `0x9908b0df` (standard MT19937)
- After twist:
  - `[esi+0x9c4]` = **`0x270`** (remaining extract count = N)
  - `[esi+0x9c0]` = **`esi`** (cursor reset to `mt[0]`)

Extract sibling `FUN_00424830` (not owned): when `+0x9c4 == 0` calls this twist, then decrements remaining, reads `*cursor++`, applies temper. Init sibling `FUN_00424890` seeds with multiplier `0x6c078965` over 624 words.

---

## ABI — SEALED

| Fact | Evidence |
|---|---|
| Convention | **ESI = state\*** (register-arg leaf; decompiler `unaff_ESI`) |
| Stack args | **none** — near **`RET`** (`C3`) |
| Return | void (EAX clobbered as walk cursor) |
| Body | `004248c0`–`00424965` |
| Callees | **none** (true leaf) |

```c
// ESI = Mt19937State*
void Rng_Mt19937_Twist(void /* ESI */);
```

### State layout (fields this unit writes / walks)

| Off | Role |
|---|---|
| `+0x00` … `+0x9BF` | `uint32 mt[624]` (N dwords) |
| `+0x9C0` | `uint32* cursor` ← set to `esi` (start of mt) after twist |
| `+0x9C4` | `int remaining` ← set to **`0x270`** after twist |

Object size seen at alloc sites: **`0x9c8`** (`operator_new(0x9c8)` in `FUN_007a42d0`).

---

## Algorithm — SEALED

Standard MT19937 twist (upper/lower merge form equivalent to decompiler):

```
// y = (mt[i] & 0x80000000) | (mt[i+1] & 0x7fffffff)  expressed as:
//   ((*mt ^ mt[1]) & 0x7ffffffe ^ *mt) >> 1  ^  (mt[1]&1 ? MATRIX_A : 0)

for i in 0 .. 226:          // 0xe3 times
  mt[i] = twist_step(mt[i], mt[i+1], mt[i+397])   // +0x18d dwords

for i in 227 .. 622:        // 0x18c times
  mt[i] = twist_step(mt[i], mt[i+1], mt[i-227])   // -0xe3

mt[623] = twist_step(mt[623], mt[0], mt[396])      // wrap; -0xe2 from penultimate walk ptr

remaining(+0x9c4) = 624
cursor(+0x9c0)    = &mt[0]
```

MATRIX_A immediate in both loop bodies: **`0x9908b0df`**.

---

## Callers (xref sample)

22 xrefs / 8 caller functions including:

| Caller | Role (context) |
|---|---|
| `FUN_00424830` | extract-one (calls twist when remaining==0) |
| `FUN_007a4200` | fill 2 MiB tempered table from MT stream |
| `FUN_007a42d0` | RNG object ctor path (seed + initial twist) |
| `FUN_007212b0`, `FUN_008d7010`, `FUN_009526f0`, `FUN_00952bc0`, `FUN_00955010` | other MT consumers |

---

## Confidence

| Claim | Level |
|---|---|
| MT19937 twist (N=624,M=397,MATRIX_A) | **Confirmed** |
| ESI state base | **Confirmed** |
| cursor@+0x9c0, remaining@+0x9c4 | **Confirmed** (bytes + extract sibling) |
| Leaf / no stack args | **Confirmed** |
| Product English name | **Inferred** (constants High) |
| Temper constants (extract, not this unit) | **Out of scope** |

---

## Pseudocode (annotated)

```c
void Rng_Mt19937_Twist(void)  // ESI = state base
{
  uint *mt = unaff_ESI;       // ESI
  int i = 0xe3;               // 227 = N-M
  uint *p = mt;
  do {
    uint *next = p + 1;
    i--;
    // classic twist step with MATRIX_A 0x9908b0df, lag M=397 (0x18d)
    *p = ((*p ^ p[1]) & 0x7ffffffe ^ *p) >> 1
         ^ -(p[1] & 1) & 0x9908b0df
         ^ p[0x18d];
    p = next;
  } while (i != 0);

  i = 0x18c;                  // 396 = M-1
  do {
    uint *cur = p;
    p = cur + 1;
    i--;
    *cur = ((*cur ^ cur[1]) & 0x7ffffffe ^ *cur) >> 1
           ^ -(cur[1] & 1) & 0x9908b0df
           ^ cur[-0xe3];      // lag N-M
  } while (i != 0);

  // last element: couple with mt[0]
  *p = ((*p ^ *mt) & 0x7ffffffe ^ *p) >> 1
       ^ -(*mt & 1) & 0x9908b0df
       ^ cur[-0xe2];

  mt[0x271] = 0x270;          // remaining @ +0x9c4
  mt[0x270] = (uint)mt;       // cursor   @ +0x9c0 = &mt[0]
}
```
