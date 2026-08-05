# Review A (reconstruction fidelity): `aa_00604d40` CVOGHB_TargetingLink_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604d40` |
| **VA** | `0x00604d40` |
| **Body** | `0x00604d40`–`0x00604dab` (`ret 4`; `CC` pad after) |
| **Canonical name** | `CVOGHB_TargetingLink_ctor_Inferred` |
| **Prior scaffold** | `FUN_00604d40` / `Named_CalleeOf_…DriveControlTick_00604d40` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00604d40_CVOGHB_TargetingLink_ctor_Inferred.md` |
| **System** | `heartbeat` / combat-target (targeting-link HB) |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + `get_function_callers` / `get_function_xrefs` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct a **targeting-link heartbeat** on a pre-allocated `CVOGHBBase`-sized object (`0x28`):

1. `CVOGHBBase_ctor` (dormant, zero periods, seed lastFire)
2. Install family vtbl **`PTR_FUN_009cdfb0`**
3. `CVOGHBBase_AttachOwnerObject(this, owner)` — owner is the **attach target** (selected entity for target-side; self entity for PlayerTargetingLink wrapper)
4. Type tag **`+0x1C = 2`**
5. Dual period: **`+0x0C = −1000`** (sentinel), **`+0x08 = 1000`** (pulse ms)
6. `CVOGHBBase_Start` (clear dormant + OnStart / `vtbl+4`)

Returns `this`. Does **not** allocate, cross-link partners, or Enqueue — those are caller duties (`Object_SetSelectedTarget`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00604d40_FUN_00604d40.md` |
| Annotated | `docs/reconstruction/raw/aa_00604d40_FUN_00604d40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHB_TargetingLink_ctor_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00604d40_CVOGHB_TargetingLink_ctor_Inferred.md` |
| Parent dual (caller) | `reviews/A_aa_005172d0_Object_SetSelectedTarget.md` |
| Base layout dual | `reviews/A_aa_00508200_CVOGHBBase_ctor.md` |
| Live decompile | `0x00604d40` (2026-07-29) |
| Bytes | `read_memory` @ `0x00604d40` len 128 |
| Vtbl | `read_memory` @ `0x009cdfb0` / sibling `0x009cdfd4` |
| Callers | `Object_SetSelectedTarget` @ `0x005172d0`; `FUN_00512090` (PlayerTargetingLink wrapper) |

---

## 3. Byte seal (`read_memory` @ `0x00604d40`)

```
00604d40  6A FF                 push -1
00604d42  68 18 80 9A 00        push LAB_009a8018          ; SEH
00604d47  64 A1 00 00 00 00     mov  eax, fs:[0]
00604d4d  50                    push eax
00604d4e  64 89 25 00 00 00 00  mov  fs:[0], esp
00604d55  51                    push ecx
00604d56  56                    push esi
00604d57  8B F1                 mov  esi, ecx              ; this
00604d59  89 74 24 04           mov  [esp+4], esi
00604d5d  E8 9E 34 F0 FF        call CVOGHBBase_ctor       ; → 0x00508200
00604d62  8B 44 24 18           mov  eax, [esp+0x18]       ; owner arg
00604d66  50                    push eax
00604d67  8B CE                 mov  ecx, esi
00604d69  C7 44 24 14 00 00 00 00  mov [esp+0x14], 0      ; SEH state
00604d71  C7 06 B0 DF 9C 00     mov  dword [esi], 0x009cdfb0  ; vtbl
00604d77  E8 34 36 F0 FF        call CVOGHBBase_AttachOwnerObject ; → 0x005083b0
00604d7c  8B CE                 mov  ecx, esi
00604d7e  C7 46 1C 02 00 00 00  mov  dword [esi+0x1C], 2   ; nTypeTag
00604d85  C7 46 0C 18 FC FF FF  mov  dword [esi+0x0C], -1000 ; nPeriodSentinel
00604d8c  C7 46 08 E8 03 00 00  mov  dword [esi+0x08], 1000  ; nPeriodMs
00604d93  E8 28 34 F0 FF        call CVOGHBBase_Start      ; → 0x005081c0
00604d98  8B 4C 24 08           mov  ecx, [esp+8]
00604d9c  8B C6                 mov  eax, esi              ; return this
00604d9e  5E                    pop  esi
00604d9f  64 89 0D 00 00 00 00  mov  fs:[0], ecx
00604da6  83 C4 10              add  esp, 0x10
00604da9  C2 04 00              ret  4
```

Hex (body through `ret 4`):
`6aff6818809a0064a100000000506489250000000051568bf189742404e89e34f0ff8b442418508bcec744241400000000c706b0df9c00e83436f0ff8bcec7461c02000000c7460c18fcffffc74608e8030000e82834f0ff8b4c24088bc65e64890d0000000083c410c20400`

| Claim | Confidence | Evidence |
|---|---|---|
| ABI **`__thiscall`**: ECX = `this` HB, stack = owner, **`ret 4`** | **High** | `mov esi,ecx`; epilogue `C2 04 00` |
| Returns **`this`** in EAX | **High** | `mov eax,esi` before epilogue |
| SEH frame around base ctor + attach | **High** | push `-1` / `LAB_009a8018` / fs:[0] |
| Callee `CVOGHBBase_ctor` @ `0x00508200` | **High** | relative CALL target |
| Vtbl store **`0x009cdfb0`** before Attach | **High** | `C7 06 B0 DF 9C 00` |
| Attach owner = stack arg via `CVOGHBBase_AttachOwnerObject` @ `0x005083b0` | **High** | push arg; call; sealed Attach dual |
| **`+0x1C = 2`** type tag | **High** | imm32 store |
| **`+0x0C = −1000`**, **`+0x08 = 1000`** (dual period model) | **High** | imm32 stores; matches base dual A layout |
| **`CVOGHBBase_Start` @ `0x005081c0`** after periods | **High** | relative CALL |
| No `operator_new`, no Enqueue, no partner `+0x24` | **High** | body ends after Start |
| Decompile CF ≡ machine (field names map to sealed offsets) | **High** | same store/call order |

---

## 4. Layout writes (this unit only)

| Off | Value | Role (from base dual + this) |
|----:|---|---|
| +0x00 | `PTR_FUN_009cdfb0` | family vtbl (target-side keeps this) |
| +0x08 | `1000` | `nPeriodMs` — TryFire pulse 1 s |
| +0x0C | `−1000` | `nPeriodSentinel` — Reschedule/SetPeriod domain |
| +0x18 | via Attach | `pOwnerObject` = ctor arg |
| +0x1C | `2` | **nTypeTag** (new sealed value; siblings 0/1/4/8) |
| +0x21 | cleared by Start | was dormant=1 from base ctor |

Base ctor still zeros +0x04/+0x10, seeds +0x14 lastFire, cStopped=0 — not re-written here.

---

## 5. Vtbl `0x009cdfb0` (context, not re-owned)

| Slot | +off | Target | Family role |
|-----:|-----:|---|---|
| 0 | +0x00 | `0x00512070` | scalar dtor family |
| 1 | +0x04 | `0x00508270` | OnStart → `CVOGHBBase_StampLastFireTime` |
| 2 | +0x08 | `0x005082c0` | `CVOGHBBase_TryFire` |
| 3 | +0x0C | `0x00604dd0` | OnHeartBeat (shared with PlayerTargetingLink vtbl) |
| 4 | +0x10 | `0x005081e0` | OnEnd family |
| … | | `0x00604ca0` / `0x00604ce0` / `0x0056f570` | residual slots |

Sibling self vtbl **`0x009cdfd4`** (set by `FUN_00512090` **after** this ctor): same OnStart/TryFire/OnHB; **different** dtor + last slot. RTTI destroy path (`0x005121d0`) only matches **PlayerTargetingLink**.

---

## 6. Callers (OWN boundary = this body; callers for role seal)

| Caller | Site | Role |
|---|---|---|
| `Object_SetSelectedTarget` `0x005172d0` | `0x005173a0` | `new(0x28)` → **this**(newTarget) → target-side HB of dual pair |
| `FUN_00512090` | `0x00512098` | `this`(owner) then overwrite vtbl → **`0x009cdfd4`** PlayerTargetingLink (self-side) |

So this unit is the **shared construction core** for both ends of the targeting-link pair; only the self wrapper changes vtbl after return.

---

## 7. Algorithm (authoritative)

```
// __thiscall CVOGHB_TargetingLink_ctor_Inferred(thisHb, pOwner)
// ECX = thisHb (0x28 storage); stack = pOwner; ret 4; returns thisHb
SEH_prolog;
CVOGHBBase_ctor(thisHb);
thisHb->pVTable = &PTR_FUN_009cdfb0;          // 0x009cdfb0
CVOGHBBase_AttachOwnerObject(thisHb, pOwner); // +0x18 + owner list mgr
thisHb->nTypeTag        = 2;                  // +0x1C
thisHb->nPeriodSentinel = -1000;              // +0x0C
thisHb->nPeriodMs       = 1000;               // +0x08
CVOGHBBase_Start(thisHb);                     // clear +0x21, OnStart vtbl+4
return thisHb;
```

---

## 8. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| SEH + base ctor | **Yes** |
| Vtbl 009cdfb0 | **Yes** |
| Attach owner | **Yes** |
| type=2, periods −1000/1000 | **Yes** |
| Start + return this + ret 4 | **Yes** |
| No Enqueue / partner link | **Yes** |

---

## 9. Gaps / open

1. Product C++ type name for vtbl `009cdfb0` (no string in body; **not** RTTI-matched as PlayerTargetingLink).
2. English meaning of type tag **2** vs 1/4/8 catalog (value sealed; enum name open).
3. Full semantics of OnHeartBeat `0x00604dd0` / destroy path (callee-owned residual).
4. Whether any path constructs this without later Enqueue (static: only SetSelectedTarget + self wrapper).
5. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps** — construction contract, ABI, constants, and dual-period layout sealed High; product type English + OnHB residual open.
