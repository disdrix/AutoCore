# Review A (reconstruction fidelity): `aa_00979c70` ClientSpecialEvent_Respawn_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979c70` |
| **VA** | `0x00979c70` |
| **Canonical name** | `ClientSpecialEvent_Respawn_dtor` |
| **System** | `client / special-event` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00979c70_ClientSpecialEvent_Respawn_dtor.md` |
| **Verdict** | **accept-with-gaps** |
| **Evidence** | Ghidra MCP `batch_decompile` 2026-07-29; raw/annotated/clean three-rep present |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00979c70_ClientSpecialEvent_Respawn_dtor.md` |
| Raw | `docs/reconstruction/raw/aa_00979c70_ClientSpecialEvent_Respawn_dtor.md` |
| Annotated | `docs/reconstruction/raw/aa_00979c70_ClientSpecialEvent_Respawn_dtor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ClientSpecialEvent_Respawn_dtor.cpp` |

---

## 2. Purpose (from unit)

Destructor / teardown for **ClientSpecialEvent_Respawn** (airlift ship special event). Sequence:

1. SEH frame; set vtbl to **`PTR_ClientSpecialEvent_Respawn_Update_00a76720`** (dtor-phase vtbl).
2. If **ship object** `this[4]` non-null:
   - If ship+8 and **attachment** `this[5]`: `FUN_0096d550(this[5])` (detach/unlink).
   - Adjust this-pointer for multi-inherit; `FUN_00944d50` cleanup.
   - Virtual call **vtbl+0x2a8** with global `*(DAT_00d1b644 + 0xe4e8)` (likely world/map context).
   - Virtual dtor of ship (`vtbl[0](1)` delete).
3. If attachment `this[5]`: virtual dtor delete.
4. Lookup object via `FUN_004bb010(this+10)` (TFID/ref at +0x28):
   - Virtual **+0x210**(0); if result equals **`DAT_00d1b6d8`** (local player):
     - restore camera/target: `*(DAT_00d1b778 + 0x60c) = this[3]`
     - `FUN_0090dd50()` camera refresh
5. Base teardown `FUN_00979290()`; set vtbl to **`PTR_LAB_00a766f8`** (base ClientSpecialEvent); return.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Two-phase vtbl write (Update ptr → base LAB) | **High** | Explicit stores |
| Ship at this[4]; attachment this[5]; saved cam/target this[3] | **High** | Field uses |
| Local-player gate vs DAT_00d1b6d8 before camera restore | **High** | Compare |
| Camera store at DAT_00d1b778+0x60c | **High** | Store site |
| Ship/attachment deleted with virtual dtor(1) | **High** | Pattern |
| Semantic names of FUN_0096d550 / FUN_00944d50 / FUN_0090dd50 | **Medium** | Unnamed |
| Clean ≡ raw CF | **High** | Scaffold |
| Runtime | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| vtbl → Respawn_Update; ship branch | **Yes** |
| attachment unlink; ship virtuals; ship delete | **Yes** |
| attachment delete | **Yes** |
| player lookup; local-only camera restore | **Yes** |
| base dtor + base vtbl | **Yes** |

---

## 5. Gaps

1. Name FUN_0096d550 (detach), FUN_00944d50, FUN_0090dd50 (camera), FUN_004bb010 (lookup).
2. Seal multi-inherit this-adjust formula for ship object.
3. Confirm DAT_00d1b6d8 is local player / controlled entity singleton.

**Verdict:** **accept-with-gaps**
