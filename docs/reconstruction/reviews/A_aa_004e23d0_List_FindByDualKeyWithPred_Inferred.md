# Review A (reconstruction fidelity): `aa_004e23d0` List_FindByDualKeyWithPred_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e23d0` |
| **VA** | `0x004e23d0` |
| **Body span** | `004e23d0` – `004e240c` (leaf; 7 BBs) |
| **Canonical name** | `List_FindByDualKeyWithPred_Inferred` |
| **Ghidra name** | `FUN_004e23d0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B seal — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_004e23d0_List_FindByDualKeyWithPred_Inferred.md` |
| **System** | shared container / reaction + client object maps |
| **Dual status** | **Present (first dual A/B)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Pure **singly-linked list find-by-dual-key with predecessor out-param**.

```
// this+4 = head
// node+0x10 = next; node+0x18 = keyLo; node+0x1c = keyHi
// *outPred = previous node (0 if match is head / empty list)
// return = matching node* or 0  (EAX; decompiler printed void)
int List_FindByDualKeyWithPred_Inferred(void *list, int keyLo, int keyHi, int *outPred);
```

Leaf: **no calls**, cyclomatic complexity **5**, `__thiscall` + `ret 0xc`.

Parent-seed alias `Named_CalleeOf_CVOGReaction_SpawnObject_004e23d0` is **not exclusive** (27 xrefs).

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_004e23d0_FUN_004e23d0.md` | ≡ live decompile (+ seal append) |
| Annotated | `docs/reconstruction/raw/aa_004e23d0_FUN_004e23d0.annotated.md` | Strengthened this pass |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004e23d0.cpp` | CF ≡ raw; `int` return sealed |
| Named alias clean | `reconstructed-exact/Named_CalleeOf_CVOGReaction_SpawnObject_004e23d0.cpp` | Parent-seed only |
| Function record | `docs/reconstruction/functions/aa_004e23d0_FUN_004e23d0.md` | Strengthened this pass |
| Live decompile | Ghidra MCP `decompile_function` @ `0x004e23d0` | **≡ raw** |
| Live `read_memory` | body @ `0x004e23d0` | Entry + `ret 0xc` sealed |
| Signature | `get_function_signature` | leaf, 25 insn, 7 BB, cc=5 |
| Bounds | `get_function_by_address` | `004e23d0`–`004e240c` |
| Callers | `get_function_xrefs` (27 sites) | reaction / resolve / maps |

**Not performed:** Launcher, runtime golden, bit-exact binary diff. **No ledgers.**

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature: thiscall; 3 stack args (`keyLo`, `keyHi`, `outPred*`) | **High** | `ret 0xc`; prologue uses ECX + stack |
| Head at `this+4` | **High** | `mov eax,[ecx+4]` |
| Next at `node+0x10` | **High** | live decompile + bytes |
| Key pair at `+0x18` / `+0x1c` | **High** | live |
| `*outPred` cleared then set only on mismatch steps | **High** | for-body assignment |
| Return value is final cursor (match or 0) in EAX | **High** | asm; callers use return; decompiler void is gap |
| Leaf / no callees | **High** | signature `call_count=0` |
| Many consumers use CoidLo/CoidHi as keys | **High** | e.g. `FUN_0092ff00`, reaction |
| Product English name | **Probable** (`_Inferred`) | no string/RTTI on this VA |
| Exclusive SpawnObject helper | **Falsified** | 27 xrefs |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| `node = *(this+4)` | **Yes** |
| `*outPred = 0` | **Yes** |
| Loop while node && (keyLo!=node+0x18 \|\| keyHi!=node+0x1c) | **Yes** |
| Body: `*outPred = node` | **Yes** |
| Step: `node = *(node+0x10)` | **Yes** |
| Exit with node = match or 0 | **Yes** |
| No invent hash / tree / string key | **Yes** |
| Clean returns `iVar1` (asm EAX; decompiler void gap) | **Yes** (documented) |

### 4.1 Live decompile (2026-07-29)

```c
void __thiscall FUN_004e23d0(int param_1,int param_2,int param_3,int *param_4)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *param_4 = 0;
  for (; (iVar1 != 0 && ((param_2 != *(int *)(iVar1 + 0x18) || (param_3 != *(int *)(iVar1 + 0x1c))))
         ); iVar1 = *(int *)(iVar1 + 0x10)) {
    *param_4 = iVar1;
  }
  return;
}
```

### 4.2 Return-type correction (asm + callers)

Decompiler `void` is incomplete: after the loop, **EAX holds `iVar1`**. Clean:

```c
return iVar1;
```

Callers e.g. `FUN_004e3260`: `iVar1 = FUN_004e23d0(...); if (iVar1==0) return 0; return *(iVar1+0xc);`.

---

## 5. Surviving contract for AutoCore

```
List_FindByDualKeyWithPred_Inferred(list, keyLo, keyHi, outPred):
  node = list->head          // *(this+4)
  *outPred = 0
  while node != 0 and (node->keyLo != keyLo or node->keyHi != keyHi):
    *outPred = node
    node = node->next        // +0x10
  return node                // match or null

// Port tests:
//  - empty head → return 0, *outPred=0
//  - match head → return head, *outPred=0
//  - match mid  → return node, *outPred=prev
//  - miss       → return 0, *outPred=last walked
//  - keys are two dwords; do not invent string hash
```

---

## 6. Open questions

1. Official product / template name for the list element.
2. Whether all 27 sites share one payload type at `+0xc`.
3. Runtime CE validation of pred out-param on insert/remove paths.
4. Whether any site passes non-Coid dual keys.

**Verdict:** **accept-with-gaps** — CF, layout, pred semantics, thiscall, and EAX return sealed; product name and full caller English remain open.
