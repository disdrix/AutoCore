# Review A (reconstruction fidelity): `aa_00419bd0` CNDHash_FreelistPop_Node0x28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419bd0` |
| **VA** | `0x00419bd0` |
| **Body** | `0x00419bd0`–`0x00419c2e` (**94** bytes; `ret` / `c3`) |
| **Canonical name** | `CNDHash_FreelistPop_Node0x28` (inferred) |
| **Ghidra name** | `FUN_00419bd0` |
| **Prior alias** | `Mission_Uses_CVOGReaction_FailMissionNotify_00419bd0` (**reject** — callee keyword contamination) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B, W22-K) |
| **Counterpart** | `reviews/B_aa_00419bd0_CNDHash_FreelistPop_Node0x28.md` |
| **System** | container / CNDHash (u64-key; inventory-sheet family) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_callers`, `get_function_callees` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Lazy freelist pop** for fixed-size **0x28-byte** CNDHash nodes (u64-key layout used by insert `0x00413920`):

1. `EDI` = `Node **` freelist head (callers: `hash + 0x20`).
2. If head null **or** `*head == 0` (empty / terminator):
   - `slab = _aligned_malloc(1000, 0x10)`
   - Track slab: `CVOGReaction_FailMissionNotify(&slab)` with **ECX = EDI+4** — dual of `0x004149d0` = **Vector_PushDword** (not mission fail)
   - `*head = slab`
   - Chain **0x18** freelist links at stride **+0x28**
   - Terminator: `[slab + 0x3c0] = 0`
3. **Pop:** `EAX = *head; *head = EAX->next` (decompiler prints only the store).

**Not** mission logic. Twin pattern of `CNDHash_FreelistPop_Node0x1c` (`0x0053ada0`) and `AlignedFreelist_PopSlot_0x160` (`0x00480460`).

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00419bd0_FUN_00419bd0.md` | W22-K live append ≡ decompile |
| Annotated | `docs/reconstruction/raw/aa_00419bd0_FUN_00419bd0.annotated.md` | machine CF sealed |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00419bd0.cpp` | CF ≡ raw |
| Named clean | `docs/reconstruction/reconstructed-exact/CNDHash_FreelistPop_Node0x28.cpp` | portable + return |
| Function record | `docs/reconstruction/functions/aa_00419bd0_FUN_00419bd0.md` | dual sealed |
| Live decompile | Ghidra `0x00419bd0` | ≡ raw scaffold |
| Live body | `read_memory` length 128 (94 used) | hex sealed below |
| Meta | body `00419bd0`–`00419c2e` | 94 bytes |
| Sibling insert | `A_aa_00413920_CNDHash_Insert_u64` | EDI=`hash+0x20`, node 0x28 |
| Slab track dual | `A_aa_004149d0` | Vector_PushDword |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `00419bd0`–`00419c2e`, `ret` (`c3`) | **Confirmed** | meta + epilogue bytes |
| EDI = freelist head pointer | **Confirmed** | `mov eax,[edi]`; insert dual |
| Empty: null head **or** `*head==0` | **Confirmed** | `test/jz` + `cmp [eax],0 / jnz` |
| `_aligned_malloc(1000, 0x10)` | **Confirmed** | `68 e8 03 00 00` / `6a 10` |
| Track via `0x004149d0` ECX=`EDI+4` | **Confirmed** | `8d 4f 04` + relative call |
| Link stride **0x28** | **Confirmed** | `8d 48 28` / decomp `piVar2+10` |
| Loop count **0x18** | **Confirmed** | `ba 18 00 00 00` |
| Terminator @ **+0x3c0** | **Confirmed** | `c7 86 c0 03 00 00 00 00 00 00` |
| Pop advances head | **Confirmed** | `8b 07 8b 08 89 0f` |
| EAX = popped node | **Confirmed** | `mov eax,[edi]` before advance; insert assigns return |
| FailMissionNotify ≠ mission | **High** | callee dual Vector_PushDword |
| Product English name | **Probable** | inferred family |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Empty check | **Yes** |
| Aligned slab alloc 1000/0x10 | **Yes** |
| Register slab (vector push residue) | **Yes** |
| Chain 0x18 × 0x28 | **Yes** |
| Zero terminator @ 0x3c0 | **Yes** |
| Pop head → EAX | **Yes** (clean named returns; raw void print) |
| `ret` no stack args | **Yes** |

### Recovered CF

```c
// EDI = Node **pHead; return Node* in EAX
Node *CNDHash_FreelistPop_Node0x28(void)
{
    if (*pHead == 0 || *(int *)*pHead == 0) {
        Node *slab = _aligned_malloc(1000, 0x10);
        Vector_PushDword(/*this=*/(char*)pHead + 4, &slab);
        *pHead = slab;
        Node *cur = slab;
        for (int i = 0x18; i != 0; --i) {
            *(Node **)cur = (Node *)((char *)cur + 0x28);
            cur = (Node *)((char *)cur + 0x28);
        }
        *(int *)((char *)slab + 0x3c0) = 0;
    }
    Node *popped = *pHead;
    *pHead = popped->next;
    return popped;
}
```

### Body hex (94 bytes)

```
518b0785c07405833800754b566a1068e8030000ff15ac659c008bf083c408
8d442404508d4f0489742408e8d0adffff89378bc6ba180000008da42400000000
83ea018d482889088bc175f4c786c0030000000000005e8b078b08890f59c3
```

### Arithmetic seal

| Quantity | Value |
|---|---|
| Node size | `0x28` |
| Usable nodes | `0x18` (24) |
| Bytes used by nodes | `24 * 0x28 = 0x3c0` |
| Terminator slot | `+0x3c0` (next = 0) |
| Slab | `1000` = `0x3c0 + 0x28` |

---

## 5. Layout (fields this unit touches)

**Freelist control (EDI):**

| Off | Role |
|---|---|
| `+0` | `Node *head` |
| `+4` | slab-tracking vector `this` (ECX into Vector_PushDword) |

**Node (freelist state only):** first dword = next link.

---

## 6. Callers / callees

**Callees:** `_aligned_malloc`, `CVOGReaction_FailMissionNotify` (`0x004149d0`).

**Callers (Ghidra):** `00413920`, `00419620`.

---

## 7. Gaps / open

1. English product name not PDB-proven — keep inferred.
2. Full freelist object field product names beyond head/+4.
3. NULL slab OOM path absent in retail body.
4. Runtime multi-slab growth not harnessed.

**Verdict:** **accept** — ABI, CF, stride, slab math, and return width sealed from decompile + body bytes.
