# Review A (reconstruction fidelity): `aa_005f44c0` GameUtils_createRagDoll

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f44c0` |
| **VA** | `0x005f44c0`–`0x005f4ed9` |
| **Canonical name** | `GameUtils_createRagDoll` |
| **Ghidra name** | `FUN_005f44c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-F) |
| **Counterpart** | `reviews/B_aa_005f44c0_GameUtils_createRagDoll.md` |
| **System** | GameUtils / ragdoll |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; plate strings; sole caller |
| **Verdict** | **accept** |

---

## 1. Purpose

**`GameUtils::createRagDoll`** — match ragdoll buffer bones to a gfx Body skeleton, build pose/parent maps and subsystem objects on the owner context, return success/failure.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005f44c0_FUN_005f44c0.md` (+ W26-F append) |
| Annotated | `docs/reconstruction/raw/aa_005f44c0_FUN_005f44c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GameUtils_createRagDoll.cpp` |
| Clean twins | `FUN_005f44c0.cpp`, `Named_GameUtils_createRagDoll.cpp` |
| Function | `docs/reconstruction/functions/aa_005f44c0_GameUtils_createRagDoll.md` |
| Live | decompile ≡ raw; prologue SEH; epilogue `5B8BE55DC3` |
| Plate | two `GameUtils::createRagDoll() error...` strings |
| Caller | `FUN_005911b0` @ `0x0059195e` |

---

## 3. Signature (sealed)

```c
// cdecl; EAX bool-as-u32
uint32_t GameUtils_createRagDoll(int param_1, int param_2, int param_3);
```

| Formal | Role | Conf |
|---|---|---|
| param_1, param_2 | buffer parse inputs (`FUN_005f4380`) | **High** |
| param_3 | owner (Body `+0x914`, outs `+0x50..+0x5c`) | **High** |
| return | 0 fail / 1 success | **High** |
| cleanup | plain `RET` (cdecl) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| Param validation + plate log | **Yes** | **High** |
| Parse bone count + limits 0x21/0x41 | **Yes** | **High** |
| Vector ensure / alloc pose stride 0x20 | **Yes** | **High** |
| Name normalize space→`_` + match | **Yes** | **High** |
| Parent walk via bone `+0x148` | **Yes** | **High** |
| Success outs @+0x50..+0x5c / return 1 | **Yes** | **High** |
| Bones-not-found fail / return 0 | **Yes** | **High** |
| SEH / unreachable EH edges | **Yes** (warnings only) | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue:
```
558bec83e4f06aff68a47a9a0064a100000000506489250000000081ec68010000...
```

Epilogue @ end: `5B 8B E5 5D C3`. Body size **2586 B** inclusive.

---

## 6. Gaps

- Nested helpers (`005f4380`, `005f5190`, `005f5490`, …) not OWN — residual.
- Full bone struct product field English beyond offsets used.
- Decompiler EH “unreachable” blocks — non-semantic for main CF.
- Runtime / differential — open.

---

## 7. Verdict

Plate name, ABI, validation/limits, match loop structure, success/fail returns, and sole caller wiring are sealed. Nested helper duals remain open by design. → **accept**.
