# Review A (reconstruction fidelity): `aa_006173a0` Map_ConstructIntKeyNode_0x18

| Field | Value |
|---|---|
| **Stable ID** | `aa_006173a0` |
| **VA** | `0x006173a0`–`0x006173de` |
| **Canonical name (Ghidra)** | `FUN_006173a0` |
| **Proposed name** | `Map_ConstructIntKeyNode_0x18` (**High** role; size-tagged) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_006173a0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W18-L) |
| **Reviewer role** | Reconstruction fidelity (leaf node ctor) |
| **Counterpart** | `reviews/B_aa_006173a0_Map_ConstructIntKeyNode_0x18.md` |
| **System** | std map/set node construction (int-key 0x18 family) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Allocate a 0x18-byte red-black tree node and initialize link/value/color/isnil fields.**

Body (entire function):

1. `node = operator_new(0x18)`.
2. If null → return 0 (EAX).
3. Else: `+0=left`, `+4=parent`, `+8=right`, `+0xC/*value`, `+0x10=value[1]`, `+0x14=color`, `+0x15=0`.
4. Return node in EAX; **`RET 0x14`**.

### Primary use

`Map_InsertNodeAndRebalance_IntKey` (`0x005d20b0`): after size guard,  
`FUN_006173a0(header, parent, header, valuePair, color=0)` then attach + rebalance.

Also 13 other insert-style callers sharing the same node size family.

**Not** rebalance, **not** key compare / walk, **not** erase.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006173a0_FUN_006173a0.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_006173a0_FUN_006173a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_ConstructIntKeyNode_0x18.cpp` |
| Function record | `docs/reconstruction/functions/aa_006173a0_Map_ConstructIntKeyNode_0x18.md` |
| Live Ghidra | `decompile_function` `0x006173a0`; `analyze_function_complete`; callers/xrefs; `read_memory` body |
| Parent dual | `Map_InsertNodeAndRebalance_IntKey` / `Map_InsertOrFind_IntKey` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
// five stack args; RET 0x14; node* in EAX
MapNode18 * __stdcall Map_ConstructIntKeyNode_0x18(
    MapNode18 *left, MapNode18 *parent, MapNode18 *right,
    const IntPair *value, uint8_t color);
```

| Item | Evidence |
|---|---|
| Stack arity 5 | `RET 0x14` @ `0x006173dc` |
| Size 0x18 | `PUSH 0x18` / `operator_new` |
| EAX return | stores target EAX; no other return reg; OOM path leaves EAX=0 |
| Sole callee | `operator_new` @ `0x00489892` |

**Decompiler trap:** signature shown as `void` — return is node*.

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| new(0x18) | **Yes** |
| null skip init | **Yes** |
| left/parent/right order | **Yes** (parent store after right load; both sealed) |
| 2-dword value copy | **Yes** |
| color + isnil=0 | **Yes** |
| RET 0x14 | **Yes** |

**Body hex (63 B):**  
`6a18e8eb24e7ff83c40485c0742e8b4c24048b54240889088b4c240c8948088b4c24108950048b1189500c8b49048a542414894810885014c6401500c21400`

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf alloc+fill ctor | **High** | 63-byte body |
| Node size 0x18 | **High** | imm + parent dual |
| Link/value/color/isnil layout | **High** | store map |
| Shared int-key family | **High** | 14 callers; insert dual cites this |
| Product mangled name | **Tentative** | size tag in name |
| All callers strictly int/int | **Probable** | value* always 2 dwords here |

---

## 6. Gaps / open

1. Retail / PDB / mangled template name.
2. Exhaustive per-caller value type audit (layout fixed; type may vary in name only).
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — CF/ABI/layout High; product name open.
