# Review A (reconstruction fidelity): `aa_005121d0` IsPlayerTargetingLinkAndDestroy

| Field | Value |
|---|---|
| **Stable ID** | `aa_005121d0` |
| **VA** | `0x005121d0` |
| **Canonical name** | `IsPlayerTargetingLinkAndDestroy` (inferred) |
| **Ghidra name** | `FUN_005121d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-O) |
| **Counterpart** | `reviews/B_aa_005121d0_IsPlayerTargetingLinkAndDestroy.md` |
| **System** | object / combat-target / HB |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept** |

---

## 1. Purpose

**Self-side targeting HB purge predicate** used by `Object_SetSelectedTarget` when the selected target pointer changes.

1. `__RTDynamicCast` node from **`CVOGHBBase`** RTTI to **`CVOGHBPlayerTargetingLink`** RTTI.
2. If cast succeeds: **thiscall** `node->vtbl[+0x18](1, 0)` (destroy / release with flags), return **1**.
3. If cast fails: return **0** (list keeps node — e.g. base-vtbl target-side HB).

Why subclass-only: ctor dual `aa_00512090` installs vtbl `0x009cdfd4` for self-side link; target-side uses base HB ctor and is intentionally **not** purged by this RTTI filter.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005121d0` | ≡ raw body |
| Live bytes | `read_memory` 48 B @ `0x005121d0` | Full leaf + `ret 0xC` |
| RTTI strings | `read_memory` @ `0x00af8d98` / `0x00af1bb0` | `.?AVCVOGHBBase@@` / `.?AVCVOGHBPlayerTargetingLink@@` |
| Xrefs | `analyze_function_complete` | 1 xref from `0x0051733b` |
| Parent dual | `A_aa_005172d0_Object_SetSelectedTarget.md` | Call-site / list this `+0xB0` |
| Sibling ctor | `A_aa_00512090_CVOGHBPlayerTargetingLink_ctor.md` | Subclass identity |
| Raw / annotated / clean | `raw/aa_005121d0_*`, `reconstructed-exact/FUN_005121d0.cpp`, named clean | Updated |

**Not performed:** Launcher, runtime golden, bit-exact package, `disassemble_bytes`.

---

## 3. Signature (image-sealed)

```c
// free function — NOT thiscall entry
// ret 0xC  →  three stack formals (list predicate shape)
uint32_t __stdcall IsPlayerTargetingLinkAndDestroy(
    void *node,   // arg0 — only used
    void *ctx1,   // arg1 — unused in body (caller 0)
    void *ctx2);  // arg2 — unused in body (caller 0)
```

| Item | Evidence | Conf |
|---|---|---|
| Entry loads arg0 via `[esp+8]` after `push esi` | `8B 74 24 08` | **Confirmed** |
| ECX not used at entry | no `mov reg,ecx` before cast | **Confirmed** |
| `ret 0xC` | `C2 0C 00` @ `0x005121fe` | **Confirmed** |
| Decompiler 1-arg prototype | under-count vs epilogue | **Falsified** as complete ABI |
| RTTI push order target then src | `push PlayerTargetingLink; push Base` then call | **Confirmed** (MSVC `__RTDynamicCast` args) |
| Destroy `vtbl+0x18` with `(1,0)` thiscall | `push 0; push 1; mov ecx,esi; call [eax+18]` | **Confirmed** |
| Return 1 / 0 in AL | `mov al,1` / zero path | **Confirmed** |
| Sole xref predicate push | parent @ `0x0051733b` | **Confirmed** |

---

## 4. Live ≡ raw CF

```
node = arg0
cast = __RTDynamicCast(node, 0, &CVOGHBBase::RTTI, &CVOGHBPlayerTargetingLink::RTTI, 0)
if (cast != 0) {
  vtbl = *node
  vtbl[0x18/4](node, 1, 0)   // thiscall
  return 1
}
return 0
```

Clean / annotated match live decompile. No hidden stores, no globals.

---

## 5. Call-site contract (parent; not re-owned)

```
// inside Object_SetSelectedTarget after optional early +0xA0 write:
ecx = entity->hbActionList   // +0xB0
CNDDoubleList_InvokePredicateAndRemove(ecx, IsPlayerTargetingLinkAndDestroy, 0, 0)
entity->selectedTarget = newTarget  // +0xA0
```

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Full leaf CF | **Confirmed** | 11 decomp lines; 0x30-byte image seal |
| Class names from RTTI | **Confirmed** | mangled type strings |
| Predicate remove semantics (1=drop) | **High** | parent list remove-if |
| Name `IsPlayerTargetingLinkAndDestroy` | **High** (inferred) | matches parent dual wording |
| vtbl+0x18 product English | **Medium** | destroy/release with flags |
| Legacy drive-tick alias name | **Low** as primary | keep as historic alias only |

---

## 7. Gaps

1. Product symbol of vtbl slot `+0x18` (dtor vs scalar deleting dtor vs custom Release).
2. Full complete-object / base-offset RTTI metadata beyond type-desc pointers (cast succeeds in practice for subclass).
3. Runtime / bit-exact still open.

**Verdict:** **accept**.
