# Review B (skeptical / adversarial): `aa_005083b0` CVOGHBBase_AttachOwnerObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_005083b0` |
| **VA** | `0x005083b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (machine seal; prior 2026-07-23 accept) |
| **Counterpart** | `reviews/A_aa_005083b0_CVOGHBBase_AttachOwnerObject.md` |
| **Live tools** | Ghidra `decompile_function` + `force_decompile` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** (body High; decompiler callee-this lie corrected) |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Blind overwrite of owner without detach | **Falsified** — detach when old non-null **and** `*(old+0xB0)≠0` |
| 2 | Always mutates owner list | **Falsified** — both list ops gated on `owner+0xB0` |
| 3 | Owner field is not +0x18 | **Falsified** — `8B 46 18` / `89 46 18` |
| 4 | `FUN_005085b0(thisHb)` / `FUN_00508490(thisHb)` as sole this=HB | **Falsified by machine** — ECX = `*(owner+0xB0)`; stack = HB (`push esi; mov ecx,eax; call`) |
| 5 | `owner+0xB0` is embedded list head (intrusive head in owner) | **Falsified** — value is **loaded and used as object pointer** (list **manager**), not walked as head node |
| 6 | Null owner is illegal | **Falsified** — store always; attach `jz` on null |
| 7 | Store skipped when new owner null | **Falsified** — `mov [esi+18],eax` **before** attach null check |
| 8 | `__cdecl` / multi stack args / void* return | **Falsified** — `ret 4`; void; ECX this |
| 9 | Dual decompile A≠B (unstable CF) | **Falsified** — force_decompile ≡ decompile_function body |
| 10 | No callers / niche only | **Falsified** — ~36 CALL xrefs (regen, skill HB, missions, weapon track, token flag, …) |
| 11 | Finished helper body ownership in this unit | **Overstated** — helpers residual; only call **shape** sealed here |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Detach → store → attach CF | **High** | List leak / double-link / stale owner |
| `HB+0x18` owner slot | **High** | Null owner in OnHeartBeat / wrong entity |
| Callee **this = listMgr @ owner+0xB0** | **High** | Port calling helpers on HB → crash / wrong CS |
| Gate semantics (skip list when +0xB0 null) | **High** | Spurious list ops / missed detach |
| Helper internal node schema | **Tentative** | Broken chain if ported from partial RE |
| Owner static type (SimpleObject only) | **Tentative** | Skill runtime also passed as owner |

---

## 3. Cross-check against raw / machine

```
// Machine-authoritative (60-byte body)
void __thiscall AttachOwnerObject(HB* this /*ECX*/, void* pOwner /*stack*/):
  old = *(this+0x18)
  if (old && *(old+0xB0)):
      FUN_005085b0( listMgr=*(old+0xB0) /*ECX*/, hb=this /*stack*/ )
  *(this+0x18) = pOwner          // always, including null
  if (pOwner && *(pOwner+0xB0)):
      FUN_00508490( listMgr=*(pOwner+0xB0) /*ECX*/, hb=this /*stack*/ )
```

Decompiler A/B pseudocode ≡ gate structure but **lies** as `FUN_*(this)` with this=HB.  
Clean (post-2026-07-29) ≡ machine call shape.  
No invented list walk inside this unit.

### Helper call-shape residual (support only; not owned)

`force_decompile` + `read_memory` on `0x00508490` / `0x005085b0` consistent with:

| Offset on listMgr | Role (Probable) |
|---|---|
| +0x04 | `CRITICAL_SECTION` (`EnterCriticalSection`) |
| +0x1C | list head node* |
| +0x20 | tail / peer link update site |
| +0x24 | count |
| +0x28 | closed/debug flag (`char`; attach throws `0x80070005` if set) |

Node: payload @ +4 matches HB pointer search/remove; free via node vtbl `(*node)(1)`.

---

## 4. Surviving contract for AutoCore

```
// CVOGHBBase_AttachOwnerObject @ 0x005083b0
// __thiscall void(HB* this, void* pOwnerObject)

AttachOwnerObject(hb, owner):
  // 1) leave old owner's HB list if that owner has a list manager
  old = hb.pOwnerObject          // +0x18
  if old != null && old.pListMgr (+0xB0) != null:
      ListMgr_Remove(old.pListMgr, hb)     // FUN_005085b0

  // 2) rebind owner slot (null clears)
  hb.pOwnerObject = owner

  // 3) join new owner's HB list if manager present
  if owner != null && owner.pListMgr (+0xB0) != null:
      ListMgr_Insert(owner.pListMgr, hb)   // FUN_00508490

Port rules:
  - Do NOT call list helpers with HB as this
  - Do NOT treat +0xB0 as embedded intrusive head; it is a pointer to a list manager
  - Skipping list ops when +0xB0==0 is intentional (owner without HB chain)
  - Detach-before-store prevents stale membership when rebinding
  - Null owner is the clear/detach path (if prior had manager)
```

---

## 5. Open questions

1. Name `FUN_00508490` / `FUN_005085b0` and publish list-manager type.
2. Which owner classes install `+0xB0` list managers vs leave null.
3. Whether re-attach to same owner double-inserts (no identity short-circuit in this body).
4. Bit-exact / differential still deferred.

**Verdict:** **accept** (body + call-shape High; helper naming residual)
