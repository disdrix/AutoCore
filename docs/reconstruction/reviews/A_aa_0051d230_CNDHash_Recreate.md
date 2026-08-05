# Review A (reconstruction fidelity): `aa_0051d230` CNDHash_Recreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d230` |
| **VA** | `0x0051d230`–`0x0051d282` (**0x53** bytes; `ret 4`) |
| **Canonical name** | `CNDHash_Recreate` (string `"HashError:Recreate, already locked for traversal"`) |
| **Ghidra name** | `FUN_0051d230` |
| **Prior alias** | `Named_VOG_DEBUG_STOP_0051d230` (lock-warn path only) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0051d230_CNDHash_Recreate.md` |
| **System** | container / missions-progression (medal def hash) |
| **Live tools** | `batch_decompile`, `disassemble_function`, `read_memory`, xrefs/callers |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Tear down + re-allocate bucket table** for a `CNDHash` at a new power-of-two size:

```c
// __thiscall  ret 4
void CNDHash_Recreate(CNDHash *this, byte log2BucketCount);
```

1. If `this+0x1d` (traversal lock) ≠ 0 → log `"HashError:Recreate, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **continue** (no abort).
2. `FUN_0051d150(this)` — zero count, free existing nodes/buckets.
3. Store `log2BucketCount` at `this+0x1c`.
4. Zero list tail `this+0x18` and list head `this+0x14`.
5. `this+0x08 = 1 << (log2BucketCount & 0x1f)` (temporary **bucket count** `N`).
6. `FUN_0051ba40(this)` — allocate pointer table + sentinel slab (`PTR_LAB_009ce090`), then **`this+0x08 = N-1`** (mask).

Sole static caller: medal-table lazy loader `FUN_00519660` @ `0x00519689`:

```
PUSH 4
MOV ECX, 0x00b042e0   ; global medal CNDHash object
CALL FUN_0051d230     ; recreate with 16 buckets (mask 15)
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x0051d230` ≡ raw |
| Live listing | full body through `RET 4` |
| Clear helper | `FUN_0051d150` — free buckets / zero count |
| Alloc helper | `FUN_0051ba40` — twin of sealed `CNDHash_AllocBuckets_*` with sentinel vtbl `009ce090` |
| Caller | `FUN_00519660` (MedalDef table ensure) |
| Lookup consumer | `MedalDef_LookupById` `0x0051a0e0` uses same `DAT_00b042e0` |
| Raw / clean | `raw/aa_0051d230_*`, `reconstructed-exact/FUN_0051d230.cpp` |

---

## 3. Authoritative body

```text
0051d230  PUSH ESI
0051d231  MOV ESI, ECX
0051d233  CMP byte ptr [ESI+0x1d], 0
0051d237  JZ  skip_log
          log Recreate-locked + VOG_DEBUG_STOP
0051d254  MOV ECX, ESI
0051d256  CALL FUN_0051d150
0051d25b  MOV CL, [ESP+8]            ; log2
0051d25f  MOV EAX, 1
0051d264  SHL EAX, CL
0051d266  MOV [ESI+0x1c], CL
0051d269  MOV ECX, ESI
0051d26b  MOV [ESI+0x18], 0          ; listTail
0051d272  MOV [ESI+0x08], EAX        ; N = 1<<bits
0051d275  MOV [ESI+0x14], 0          ; listHead
0051d27c  CALL FUN_0051ba40          ; alloc; mask = N-1
0051d281  POP ESI
0051d282  RET 4
```

---

## 4. Layout (this body)

| Off | Field | Role |
|---|---|---|
| `+0x08` | size→mask | set to `1<<bits`, then AllocBuckets writes `N-1` |
| `+0x14` | listHead | zeroed |
| `+0x18` | listTail | zeroed |
| `+0x1c` | log2Bits (byte) | stored from arg |
| `+0x1d` | lockedForTraversal | warn-only |

---

## 5. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B ≡ raw ≡ live | **Confirmed** |
| `__thiscall` + `ret 4` | **Confirmed** |
| Lock log-only (no abort) | **Confirmed** |
| Clear then AllocBuckets path | **High** |
| Parent passes bits=`4` on `DAT_00b042e0` | **Confirmed** |
| Product name `CNDHash_Recreate` | **High** (string) |
| Full destroy semantics of `FUN_0051d150` | **Open** (callee residual) |
| Runtime recreate under lock | **Open** |

**Verdict:** **accept-with-gaps.**
