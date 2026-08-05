# Review B (skeptical / adversarial): `aa_0096c8e0` EffTextureImpl_ReleaseGpu_Unaccount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096c8e0` |
| **VA** | `0x0096c8e0` |
| **Canonical name** | `EffTextureImpl_ReleaseGpu_Unaccount_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0096c8e0_EffTextureImpl_ReleaseGpu_Unaccount_Inferred.md` |
| **System** | palantir graphics Effects — effTextureImpl |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a full C++ destructor | No operator_delete; no vtbl store; object remains | **Falsified** dtor claim |
| 2 | Stdcall / stack this | Prolog `mov edi,ecx`; callers load ECX | **Falsified** stdcall-this |
| 3 | RET 4 / cleans stack args | Epilogue plain `C3` | **Falsified** |
| 4 | Always unaccounts even when no GPU | Gate on `+0x10 != 0` before stats; still nulls trio | **Partial** — unaccount gated, Release always |
| 5 | gfxDevice method (scaffold name) | Body is impl-shaped; create path is first caller; Reset only walks list of impls | **Falsified** device-method plate |
| 6 | Stats offsets invented | Create path adds same offsets; pair is exact inverse | **Falsified** invent claim |
| 7 | Type 2/4 meaning free-form | Create: low-nibble 2→CreateCubeTexture, 4→CreateVolumeTexture, 1→CreateTexture | **Agree High** cube/volume/2D |
| 8 | Merges with factory ReCreate | Distinct VA; factory only *calls* create which *calls* this | **Falsified** merge |
| 9 | `FUN_0096c730` is thiscall ECX | Decompiler unaff_EDI; parent keeps EDI=this; not ECX after entry | **Agree** custom EDI ABI (gap on helper dual) |
| 10 | Returns HRESULT | void; last EAX is last Release refcount — not a contract | **Falsified** hr-return claim |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Thiscall + 378 B + plain RET | **Confirmed** | Stack imbalance |
| Release+null `+0x10/+0x14/+0x18` | **Confirmed** | GPU leak |
| Stats banks vs create | **Confirmed** | Double-count / undercount |
| Type nibble cube/volume/2D | **High** | Wrong bank |
| Flag `0x1000` product label | **Open** | Misname only |
| Nested size helpers | **Open** | Wrong byte totals if helpers misread |
| Runtime | **Open** | No live Reset capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live batch_decompile (2026-08-04)
body 378 B ends C3; pad CC then FUN_0096ca60

Prolog: push ebx/ebp/esi/edi; mov edi,ecx; xor ebp,ebp
Gate: cmp [edi+0x10], ebp
Flags: mov eax,[edi+0x2c]; test ah,0x10  (bit 0x1000)
Size: call FUN_0096c730 (EDI preserved) or FUN_0096c810(edi)
Depth: mov esi,edi; call FUN_0096bb20
Release: [obj]; push; call [vtbl+8]; mov [edi+off], ebp  ×3
Epilogue: pop edi/esi/ebp/ebx; ret
```

### Call-site trap

Some decompiles show `FUN_0096c8e0()` with **no** formals (e.g. `FUN_0048ed90` scaffold). **Bytes win**: thiscall ECX=impl. Parent list walk: `mov ecx,[node+8]`.

### Naming trap

Scaffold `Named_CalleeOf_Named_gfxDevice_*` is xref noise from Reset — reject as product plate. Structural host is **effTextureImpl** (create path `effTextureImpl.cpp`, fields match create).

### Stats trap

Do **not** invent counters without create pair — every release delta has a matching create `+` at same offset under `DAT_00d1f614`.

---

## 4. Residual risks

| Risk | Severity | Mitigation |
|---|---|---|
| Wrong product flag labels | Low | Keep `_Inferred`; document bits only |
| Size helper EDI/ESI ABI mis-port | Med | Port helpers with register ABI notes |
| Unowned create dual | Med | Port create before relying on formal list |

---

## 5. Verdict

Attacks on dtor / stdcall / device-method / invented stats fail. Core CF/ABI/COM/stats sealed. Product English + nested helpers open → **accept-with-gaps**.
