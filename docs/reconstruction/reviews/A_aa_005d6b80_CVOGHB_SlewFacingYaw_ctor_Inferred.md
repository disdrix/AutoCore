# Review A (reconstruction fidelity): `aa_005d6b80` CVOGHB_SlewFacingYaw_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6b80` |
| **VA** | `0x005d6b80`–`0x005d6c0f` |
| **Canonical name** | `CVOGHB_SlewFacingYaw_ctor_Inferred` |
| **Ghidra name** | `FUN_005d6b80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-K) |
| **Counterpart** | `reviews/B_aa_005d6b80_CVOGHB_SlewFacingYaw_ctor_Inferred.md` |
| **System** | heartbeat / creature facing |
| **Evidence pass** | Live `decompile_function` + `read_memory` + callers/callees/xrefs; sealed slew dual `004c7bd0`; parent factory W27-I |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Secondary period HB ctor (size **0x28**): base construct, install vtbl `009daee8`, seed pulse **30 ms**, schedule sentinel −1000, stash raw owner, attach MI-adjusted owner, zero facing float `owner+0x11c`, run one `CVOGCreature_SlewFacingYaw_Inferred(owner, 30)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d6b80_FUN_005d6b80.md` (+ W28-K append) |
| Annotated | `docs/reconstruction/raw/aa_005d6b80_FUN_005d6b80.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHB_SlewFacingYaw_ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d6b80.cpp` |
| Function | `docs/reconstruction/functions/aa_005d6b80_CVOGHB_SlewFacingYaw_ctor_Inferred.md` |
| Sealed callee | `CVOGCreature_SlewFacingYaw_Inferred` (`aa_004c7bd0`) |
| Parent factory | `Object_EnsurePrimaryHBAI_FromAIProfile` secondary `def+0x4e8` |
| Vtbl | `PTR_FUN_009daee8` (`read_memory`) |

---

## 3. Signature

```c
// Ghidra: undefined4 * __thiscall FUN_005d6b80(undefined4 *param_1, void *param_2)
// Bytes: SEH frame; … ADD ESP,10; RET 4
void * __thiscall CVOGHB_SlewFacingYaw_ctor_Inferred(void *self, void *pOwnerRaw);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B F1` / ESI=this | **High** |
| stack owner; RET 4 | `C2 04 00` | **High** |
| returns this | `8B C6` before epilogue | **High** |
| SEH present | `LAB_009a7138` + ExceptionList | **High** |

---

## 4. Control flow (sealed)

1. `CVOGHBBase_ctor(self)`
2. `*self = PTR_FUN_009daee8`
3. `*(self+8) = 0x1e`
4. `CVOGHBBase_SetPeriodAndCounter(self, -1000, true)`
5. `*(self+0x24) = pOwnerRaw`
6. MI-adjust owner if non-null → `CVOGHBBase_AttachOwnerObject`
7. `*(float*)(pOwnerRaw+0x11c) = 0` (xorps/movss)
8. `CVOGCreature_SlewFacingYaw_Inferred(pOwnerRaw, 0x1e)` — **ECX=raw owner** (byte seal; decompiler residual)
9. restore ExceptionList; return self

| Stage | Match | Conf |
|---|---|---|
| Base ctor + vtbl install | **Yes** | **High** |
| Pulse 0x1e @ +8 | **Yes** | **High** |
| SetPeriodAndCounter(−1000,true) | **Yes** | **High** |
| Raw stash + MI attach | **Yes** | **High** |
| Zero + slew on raw owner | **Yes** (bytes) | **High** |
| Sole factory secondary caller | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr | Role |
|---|---|
| prolog | `6A FF 68 38 71 9A 00` SEH |
| vtbl store | `C7 06 E8 AE 9D 00` → `009daee8` |
| period | `C7 46 08 1E 00 00 00` |
| zero facing | `0F 57 C0` / `F3 0F 11 80 1C 01 00 00` |
| slew call setup | push `[esi+8]`; `mov ecx,[esi+24]`; `call FUN_004c7bd0` |
| epilogue | `83 C4 10 C2 04 00` |

---

## 6. Gaps / open

1. Product/PDB English class name for `009daee8`.
2. Shared plate name for HB `+0x24` raw-owner stash across size-0x28 HBs.
3. Tick sibling `FUN_005d6c10` not OWN (period re-slew contract residual for full class seal).
4. Runtime / bit-exact — open.

---

## 7. Verdict

CF/ABI/vtbl/factory/slew this-arg sealed; product class English residual → **accept-with-gaps**.
