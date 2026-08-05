# Review B (skeptical / adversarial): `aa_00604d40` CVOGHB_TargetingLink_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604d40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00604d40_CVOGHB_TargetingLink_ctor_Inferred.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callers/xrefs + sibling `0x00512090` / vtbls |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is only the “target-side” ctor; self uses a separate full ctor | **Falsified as exclusive** — `FUN_00512090` **calls this** then swaps vtbl to `009cdfd4` |
| 2 | Same class as `CVOGHBPlayerTargetingLink` (RTTI) | **Falsified for vtbl kept here** — destroy predicate RTTI-matches only PlayerTargetingLink (`009cdfd4` path); this installs **`009cdfb0`** |
| 3 | Period “always ready” because decompile shows −1000 near period fields | **Partial falsify of alias** — **−1000 is at +0x0C** (sentinel); **+0x08 = 1000** is real pulse. TryFire gates on **+0x08**, not +0x0C |
| 4 | `nUnusedOrFlags=2` is a free flags bitfield | **Falsified as unused** — sealed family **type tag** at +0x1C (siblings write 1/4/8) |
| 5 | Ctor Enqueues onto world HB list | **Falsified** — no `CVOGHBList_Enqueue`; parent `Object_SetSelectedTarget` enqueues after cross-link |
| 6 | Ctor allocates `0x28` | **Falsified** — no `operator_new`; caller allocs |
| 7 | Stack-free / bare `ret` thiscall | **Falsified** — **`ret 4`** (one stack owner arg) |
| 8 | Start runs with final PlayerTargetingLink vtbl on self path | **Falsified timing** — self wrapper: Start runs **while** vtbl still `009cdfb0`; then `00512090` overwrites to `009cdfd4`. OnStart slot is **identical** (`0x00508270`) so behavior matches, but vtbl identity at OnStart is base family |
| 9 | Scaffold name “Named_CalleeOf_…DriveControlTick” is the product role | **Falsified** — only **2** xrefs: SetSelectedTarget + PlayerTargetingLink wrapper; DriveControlTick is an **indirect** parent of SetSelectedTarget |
| 10 | Dual period fields are the same dword | **Falsified** — two imm stores: `+0x0C` then `+0x08` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ECX=this, arg=owner, ret 4, return this | **High** | Wrong ports break SetSelectedTarget |
| Vtbl `009cdfb0` install | **High** | Wrong OnHB/dtor |
| Type tag **2** | **High** (value); Low (English) | Listener/filter miss if cataloged wrong |
| Pulse **1000 ms** at +0x08 | **High** | Targeting HB cadence wrong |
| Sentinel **−1000** at +0x0C | **High** | Reschedule/combat-pool confusion if aliased to +0x08 |
| Start before return | **High** | Dormant HB never fires until external Start |
| Shared core for self+target | **High** | Duplicate ctor logic in port |
| Product class name for `009cdfb0` | **Tentative** | Naming only |
| OnHeartBeat full contract | **Not owned** | Residual `0x00604dd0` |

---

## 3. Cross-check: decompile vs machine

Decompile store order:

```
CVOGHBBase_ctor
pVTable = 009cdfb0
AttachOwner(param_2)
nUnusedOrFlags = 2      → +0x1C
nPeriodSentinel = -1000 → +0x0C
nPeriodMs = 1000        → +0x08
CVOGHBBase_Start
return param_1
```

Machine matches **exactly** (including SEH). Ghidra name `nUnusedOrFlags` is **misleading** — port as **`nTypeTag`**.

### Self-wrapper bytes (`0x00512090`) — attack on “target-only”

```
mov eax, [esp+4]     ; owner
push esi
push eax
mov esi, ecx
call 0x00604d40      ; full shared ctor + Start
mov [esi], 0x009cdfd4
mov eax, esi
pop esi
ret 4
```

**Survives:** shared construction; **self is a thin vtbl upgrade**.

### Period model (survives attack)

| Field | This ctor | TryFire / Remaining |
|---|---|---|
| +0x08 = 1000 | pulse every 1s after Start | **used** as period |
| +0x0C = −1000 | sentinel | Reschedule path; **not** the “suppress fire” TryFire gate (that is +0x08 == −1000) |

Do **not** port “period = −1000” for this unit.

---

## 4. Surviving contract for AutoCore

```
// Port of aa_00604d40 — targeting-link HB shared ctor
CVOGHBBase* CVOGHB_TargetingLink_ctor_Inferred(CVOGHBBase* thisHb, void* pOwner) {
  CVOGHBBase_ctor(thisHb);
  thisHb->pVTable = &kVtbl_TargetingLink_009cdfb0; // 0x009cdfb0
  CVOGHBBase_AttachOwnerObject(thisHb, pOwner);
  thisHb->nTypeTag        = 2;      // +0x1C
  thisHb->nPeriodSentinel = -1000;  // +0x0C
  thisHb->nPeriodMs       = 1000;   // +0x08  (1 Hz pulse)
  CVOGHBBase_Start(thisHb);
  return thisHb;
}

// Callers:
//  target-side: Object_SetSelectedTarget → new(0x28) → this(newTarget)
//               then partner-link + Enqueue
//  self-side:   FUN_00512090 → this(self) → pVTable = 009cdfd4 (PlayerTargetingLink)
```

---

## 5. Open questions

1. Product type name for `009cdfb0` (base targeting HB vs anonymous configured base).
2. Consumers of type tag **2** (if any filter mirrors skill tag-1 listener).
3. OnHeartBeat `0x00604dd0` owner-alive / destroy policy (shared by both vtbls).
4. Runtime cadence of targeting HB vs UI target chrome.
5. Bit-exact / differential vs retail image.

**Verdict:** **accept-with-gaps** — adversarial checks strengthen dual-period + shared-ctor model; product English + OnHB remain open. Residual naming scaffold “DriveControlTick callee” is **rejected**.
