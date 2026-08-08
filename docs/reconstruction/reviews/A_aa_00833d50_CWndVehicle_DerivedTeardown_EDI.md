# Review A (reconstruction fidelity): `aa_00833d50` CWndVehicle_DerivedTeardown_EDI

| Field | Value |
|---|---|
| **Stable ID** | `aa_00833d50` |
| **VA** | `0x00833d50` |
| **Body** | `0x00833d50`–`0x00833df7` exclusive (**167** B / `0xA7`) |
| **Canonical name** | `CWndVehicle_DerivedTeardown_EDI` |
| **Ghidra name** | `FUN_00833d50` |
| **Review date** | `2026-08-05` (WQ9K-E OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00833d50_CWndVehicle_DerivedTeardown_EDI.md` |
| **System** | CWndVehicle / UI derived member teardown |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context` + `disassemble_function`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Derived teardown helper for CWndVehicle: clear `+0x50C`, re-notify nested `@+0x2A8`, scalar-delete vehicle host `@+0x508` (optional child + `Vehicle_SetWheelset(0)`), null `+0x508`. EDI=this. Does not free the window or run base dtor.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9K-E re-verify) | `docs/reconstruction/raw/aa_00833d50_FUN_00833d50.md` |
| Annotated | `docs/reconstruction/raw/aa_00833d50_FUN_00833d50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWndVehicle_DerivedTeardown_EDI.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00833d50.cpp` |
| Function record | `docs/reconstruction/functions/aa_00833d50_CWndVehicle_DerivedTeardown_EDI.md` |
| Live body | `read_memory` entry/epilogue; full `disassemble_function` |
| Complete parent | dual `CWndVehicle_CompleteDtor` @ `0x00834520` (WQ9J-B) |
| Scalar parent | dual `CWndVehicle_ScalarDeletingDtor` @ `0x004160d0` (WQ9I-F) |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| EDI | CWndVehicle* this | entry `MOV ESI,[EDI+0x2A8]`; complete keeps EDI |
| stack formals | none | SUB ESP,8 locals only |
| cleanup | bare **`RET`** | `C3` @ `0x00833df6` |
| return | void | no EAX product |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + bare RET | **Confirmed** | bytes end `83 C4 08 C3` |
| EDI=this ABI | **Confirmed** | entry + complete call site |
| Clear +0x50C | **Confirmed** | `MOV [EDI+0x50C],0` |
| Nested notify +0x2A8 | **Confirmed** | flag/RDTSC/vcalls match complete plate |
| Vehicle host +0x508 scalar-delete | **Confirmed** | push 1; call [vtbl]; null slot |
| Vehicle_SetWheelset(0) | **Confirmed** | CALL `0x004fea90` after child path |
| Host class CWndVehicle | **High** | sole complete-path primary caller + RTTI chain |
| Nested product English | **Open** | type residual |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| +0x50C = 0 | **Yes** |
| nested@+0x2A8 notify plate | **Yes** |
| host@+0x508 child / SetWheelset / scalar-delete / null | **Yes** |
| no free(this) / no base dtor | **Yes** |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Called from CWndVehicle complete dtor | **Yes** |
| CWndVehicle RTTI/vtbl sealed on complete peer | **Yes** |
| Offsets match complete dual documentation | **Yes** |
| Nested host product demangle | **No** |

**Decision:** promote **`CWndVehicle_DerivedTeardown_EDI`**. Reject complete/scalar merge; reject ECX thiscall rewrite without call-site EDI fix; reject freelist/tree identity.

---

## 7. Gaps

1. Nested host `@+0x2A8` product type English.
2. Vehicle host `@+0x508` exact class name beyond wheelset usage.
3. Dual of other callers (`00833e30`, `0083ac90`, `0084b210`, Drive_Loading).
4. Runtime / bit-exact / image diff.
