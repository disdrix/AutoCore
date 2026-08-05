# Review A (reconstruction fidelity): `aa_00979310` ClientSpecialEvent_Respawn_SetupAirlift

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979310` |
| **VA** | `0x00979310` |
| **Canonical name** | `ClientSpecialEvent_Respawn_SetupAirlift` (inferred; Ghidra `FUN_00979310`) |
| **Plate alias** | `Named_AllocateNewObjectFromCbidFailed_00979310` (string-backed) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00979310_ClientSpecialEvent_Respawn_SetupAirlift.md` |
| **System** | client special-event / respawn |
| **Evidence pass** | Live decompile + callees; callers Respawn ctor `0x00979650` + Update `0x00979730`; parent duals |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Shared **Respawn special-event setup** (EDI = `ClientSpecialEvent_Respawn* this`):

1. Resolve controlled object from TFID at `this+0x28` via `FUN_004bb010`.
2. **Fail path:** if null or `obj+0x8 == 0` → set **cancel** `this+0x08 = 1` and return.
3. **Success path:** clear cancel `this+0x08 = 0`, then:
   - `CVOGReaction_GiveItemByCbid(0xadc)` airlift ship object (fail → log `"allocatenewobjectfromcbid failed %d Get a programmer"`).
   - Init / attach / random yaw quaternion / place at entity pose.
   - Load three airlift anims via `FUN_005828b0` (slots 1–3):
     - `obj_f_inc_mov_01_airlift_at.anm`
     - `obj_f_inc_mov_01_airlift_aut.anm`
     - `obj_f_inc_mov_01_airlift_at2.anm`
   - `FUN_005816a0(1, 0)` — select anim slot 1 at weight 0.
   - Optional camera path if entity matches `DAT_00d1b6d8`.
   - Force entity mode bits / `FUN_00560e90` / `FUN_0053d970(1)`.
   - Zero phase timers `this+0x18`; snapshot optional child timer into `this+0x1c/+0x20`.

Called from **ctor** (always) and from **Update** when cancel/re-enter paths need setup or re-assert cancel. Body is **setup**, not pure teardown — cancel is only the early-out flag when resolve fails.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00979310_FUN_00979310.md` |
| Annotated | `docs/reconstruction/raw/aa_00979310_FUN_00979310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00979310.cpp` |
| Function record | `docs/reconstruction/functions/aa_00979310_FUN_00979310.md` |
| Parent duals | `A_aa_00979650_*`, `A_aa_00979730_*` |
| Callee dual (this wave) | `aa_005816a0` |

**Three-rep:** present.

---

## 3. Signature

```c
// EDI = ClientSpecialEvent_Respawn* this  (unaff_EDI)
// no stack formals observed in decomp
void ClientSpecialEvent_Respawn_SetupAirlift(void /*EDI this*/);
```

| Formal | Source | Conf |
|---|---|---|
| Event `this` | **EDI** | **High** (offsets +0x08/+0x10/+0x28/+0x68 match Respawn layout dual) |
| Stack | none in decomp | **Medium** |

---

## 4. Control flow checklist

| Stage | Match | Conf |
|---|---|---|
| Resolve TFID `this+0x28` | **Yes** | **High** |
| Fail → `this+0x08=1` return | **Yes** | **High** |
| Success → `this+0x08=0` | **Yes** | **High** |
| CBID **0xadc** airlift alloc | **Yes** | **High** |
| Fail log string + return | **Yes** | **High** |
| Random unit yaw → quat (sin/cos × `_DAT_00aaaa84`) | **Yes** | **High CF** |
| Pose from entity phys or fallback | **Yes** | **High CF** |
| Three `.anm` loads + `FUN_005816a0(1,0)` | **Yes** | **High** |
| Local-player camera branch vs `DAT_00d1b6d8` | **Yes** | **Medium** (global ids open) |
| Entity mode force `+0x28=0x10` + helpers | **Yes** | **High CF** |
| Timer zeros `+0x18/+0x1c/+0x20` | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Shared Respawn setup used by ctor + Update | **High** | 2 callers only |
| Cancel flag armed on resolve fail | **High** | `this+0x08` |
| CBID 0xadc airlift object | **High** | immediate + string |
| Anim file names | **Confirmed** | string literals |
| Full product names for pose/camera helpers | **Tentative** | residual FUN_* |
| Angle scale constant semantics | **Probable** | 16-bit random × double scale |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Product name / PDB for this helper and CBID 0xadc asset.
2. Exact meaning of entity mode `0x10` and camera globals.
3. Whether Update “cancel path” always intends re-setup vs re-assert fail (behavior: always runs full setup on success).
4. Own duals for `FUN_005828b0`, `FUN_004bb010` residual.

**Verdict:** **accept-with-gaps**
