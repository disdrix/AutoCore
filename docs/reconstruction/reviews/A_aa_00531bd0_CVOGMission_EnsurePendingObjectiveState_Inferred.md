# Review A (reconstruction fidelity): `aa_00531bd0` CVOGMission_EnsurePendingObjectiveState_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531bd0` |
| **VA** | `0x00531bd0` |
| **Body** | `0x00531bd0`–`0x00531c7a` (**`ret 8`**) |
| **Canonical name** | `CVOGMission_EnsurePendingObjectiveState_Inferred` (Ghidra `FUN_00531bd0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00531bd0_CVOGMission_EnsurePendingObjectiveState_Inferred.md` |
| **System** | `missions-progression` |
| **Live tools** | Ghidra `decompile_function`, `force_decompile`, `analyze_function_complete`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF + offsets High; product name open |

---

## 1. Purpose

**Sibling of `CVOGMission_AddActiveObjective` (`0x00531b00`)** used when rehydrating character state from a create packet. Ensures a **pending objective state node** exists in **`char+0x55c`** and writes a **4×dword slot blob** into it:

1. Gate: `objDef != 0` **and** evaluator vector `[def+0x158, def+0x15c)` non-empty (`(end-begin)>>2 != 0`).
2. `CNDHash_LookupByKey(*(char+0x55c), *(def+0x10))`.
3. On miss: `operator_new(0x14)` → zero five dwords; mark **new**.
4. Always (if gate passed): write `node[0]=def`; `node[1..4]=blob[0..3]` from `param_3` (16 bytes).
5. If **new**: `CNDHash_Insert` twin **`FUN_0053c760`**(hash=`char+0x55c`, key=`def+0x10`, value=node, soft=`0`).
6. **Does not**: insert def into `+0x548`, run evaluator vcalls, or dirty `+0x634`.

Sole static caller: `CVOGCharacter_ApplyCreateFromPacket` @ `0x00534bd0` (site `0x00535505`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `force_decompile` @ `0x00531bd0` ≡ frozen raw |
| Complete analysis | 1 xref; callees `CNDHash_LookupByKey`, `operator_new`, `FUN_0053c760` |
| Machine | `read_memory` @ `0x00531bd0` length 200 |
| Sibling dual | `A_aa_00531b00_CVOGMission_AddActiveObjective.md` |
| Insert twin | `A_aa_0053c760_CNDHash_Insert.md` (state-node vtbl `009cefec`) |
| Caller plate | `reconstructed-exact/CVOGCharacter_ApplyCreateFromPacket.cpp` |
| Raw / clean / function | `raw/aa_00531bd0_*`, `reconstructed-exact/FUN_00531bd0.cpp`, `functions/aa_00531bd0_*` |

---

## 3. Authoritative body (live ≡ raw)

```c
void __thiscall FUN_00531bd0(int character /*ECX*/, int objDef, int *slotBlob4)
{
  bool isNew;
  int *node;

  if (objDef == 0) return;
  if (*(int *)(objDef + 0x158) == 0) return;
  if ((*(int *)(objDef + 0x15c) - *(int *)(objDef + 0x158)) >> 2 == 0) return;

  node = CNDHash_LookupByKey(*(void **)(character + 0x55c), *(uint *)(objDef + 0x10));
  isNew = false;
  if (node == 0) {
    node = operator_new(0x14);
    if (node) {
      node[0]=node[1]=node[2]=node[3]=node[4]=0;
    }
    isNew = true; // even if new returned null — see gaps
  }
  *node = objDef;
  node[1] = slotBlob4[0];
  node[2] = slotBlob4[1];
  node[3] = slotBlob4[2];
  node[4] = slotBlob4[3];
  if (isNew) {
    // ECX restored from [character+0x55c] in asm (decompiler drops this)
    FUN_0053c760(*(uint *)(objDef + 0x10), node, 0);
  }
}
// ret 8
```

---

## 4. Machine seal (`read_memory`)

Hex (prologue + key sites):  
`56 8b 74 24 08 85 f6 57 8b f9 0f 84 97 00 00 00 … 8b 86 58 01 00 00 … 8b 8e 5c 01 00 00 2b c8 c1 f9 02 … 8b 56 10 8b 8f 5c 05 00 00 52 e8 … 6a 14 e8 … 8b 8f 5c 05 00 00 6a 00 50 8b 46 10 50 e8 … 5f 5e c2 08 00`

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX=char; 2 stack args; **`ret 8`** | `mov edi,ecx`; ends `c2 08 00` | **High** |
| Gate `def+0x158` / `+0x15c` size | `8b 86 58 01 00 00` / `5c 01 00 00` + `c1 f9 02` | **High** |
| Lookup hash **`this+0x55c`**, key **`def+0x10`** | `8b 8f 5c 05 00 00` + `8b 56 10` + push/call | **High** |
| Node **0x14** zero-init | `6a 14` + five dword stores | **High** |
| Slot copy 4 dwords | `mov [eax],esi`; four stores via blob ptr | **High** |
| Insert only if new via `FUN_0053c760` | conditional path + `push 0; push node; push key; call` | **High** |
| No `+0x548` / no dirty `+0x634` / no vcall `+0x28` | body has no such ops | **High** |
| Decompiler drops insert ECX | asm reloads `[edi+0x55c]` before call | **High** |

---

## 5. Contrast vs `AddActiveObjective` (`0x00531b00`)

| Step | AddActiveObjective | This unit |
|---|---|---|
| Def-hash `+0x548` insert | Always | **Never** |
| Pending `+0x55c` | New node + insert | Lookup-or-create + insert only if new |
| Slot blob write | Only `node[0]=def` | **`node[0]=def` + 4 dwords from arg** |
| Evaluator vcall `+0x28` | Yes | **No** |
| Dirty `+0x634 \|= 0x10` | When evaluators present | **No** |
| Caller | GiveMission / CompleteObjective | ApplyCreateFromPacket only |

---

## 6. Gaps / open

1. Product symbol (inferred from sibling + sole caller).
2. Null `operator_new` then write-through (decompiler/asm both allow UAF-style null write if OOM — retail risk residual).
3. Exact packet layout of the 4 dwords (RecvObjectiveState family uses similar slots — not re-proven here).
4. Runtime / bit-exact / image diff open.

---

## 7. Safe claims

| Safe | Unsafe |
|---|---|
| Pending ensure + 4-dword slot sync | Full “mission grant” |
| No dirty / no evaluator setup | Alias as AddActiveObjective |
| `+0x55c` / key `def+0x10` / node `0x14` | Product mangled name |
| accept-with-gaps | complete |
