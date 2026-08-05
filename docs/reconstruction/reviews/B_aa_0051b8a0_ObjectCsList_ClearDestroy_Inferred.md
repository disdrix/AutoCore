# Review B (skeptical / adversarial): `aa_0051b8a0` ObjectCsList_ClearDestroy_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b8a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-F) |
| **Counterpart** | `reviews/A_aa_0051b8a0_ObjectCsList_ClearDestroy_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is Object_SharedBase_Dtor itself | **Falsified** — called FROM SharedBase dtor with ECX=`[this+0xB0]`; list-only body |
| 2 | This deletes the list object / CS | **Falsified** — only nodes; no `DeleteCriticalSection`; dtor is `FUN_0051d0e0`/`FUN_0051bf10` |
| 3 | Identical to ThreadSafeObjectList_Dtor | **Falsified** — dual-CS ThreadSafeObjectList uses PopFront + different layout; this is single CS at +4, head at +0x1C |
| 4 | Identical to List_ClearDestroy `0040dc40` | **Partial** — same algorithm family, **different** next offset (`+8` vs `+0x10`) and this unit clears `node+4` |
| 5 | ECX is SharedBase core this | **Falsified** — call sites `mov ecx,[esi+0xB0]` before call |
| 6 | Same as FUN_0051bc90 | **Near miss** — twin omits `node+4=0`; do not merge blindly |
| 7 | Product English known | **Overstated** — `_Inferred` structural only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CS drain + throw role | **High** | Leaks / hang on lock |
| ECX = helper list not core | **High** | Wrong this in port |
| Node next@+8 | **High** | Walk corruption |
| Distinct from list dtor | **High** | Double free CS |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against Object_SharedBase_Dtor (W29-G)

```
// FUN_00518ec0 @ 0x00518f6e region (bytes):
//   mov ecx, [esi+0xB0]
//   call FUN_0051b8a0          // THIS unit — clear nodes
//   mov ecx, [esi+0xB0]
//   cmp ecx, ebx / je
//   mov edx, [ecx]
//   push 1 / call [edx]        // then scalar-delete list object
```

Confirms teardown order: **drain nodes first**, then destroy helper object.

---

## 4. Surviving contract for AutoCore

```
// Port as list method (ECX = ObjectCsList* @ SharedBase+0xB0):
ObjectCsList_ClearDestroy(list);
// Must throw 0x80070005 if traversal flag +0x28 set (after LeaveCS).
// Must not DeleteCriticalSection / operator_delete(list) here.
// Node: next@+8; clear +4; scalar dtor(1).
// Keep separate from List_ClearDestroy(0040dc40) and ThreadSafeObjectList_Dtor.
```

---

## 5. Verdict

Adversarial pass confirms A on ownership, ABI, node layout, throw path, and non-dtor role. Product name residual → **accept-with-gaps**.
