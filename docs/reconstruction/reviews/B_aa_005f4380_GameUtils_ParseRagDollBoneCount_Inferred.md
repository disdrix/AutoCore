# Review B (adversarial): `aa_005f4380` GameUtils_ParseRagDollBoneCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f4380` |
| **VA** | `0x005f4380`–`0x005f441a` |
| **Canonical name** | `GameUtils_ParseRagDollBoneCount_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial / red-team (OWN-ONLY W27-H) |
| **Counterpart** | `reviews/A_aa_005f4380_GameUtils_ParseRagDollBoneCount_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Attack surface

| Claim under test | Attack | Result |
|---|---|---|
| Arity 5 vs parent surface 2 | createRagDoll decompile shows 2 args | **Rejected** — `read_memory` @ call site has **5 pushes** before `E8`; this unit formals match |
| Body size | Ghidra range exclusive? | **Rejected** — RET `C3` @ `0x005f441a`; inclusive **155 B**; pad `CC` after |
| Return meaning | Maybe not bone count | **Rejected** — parent assigns EAX to count and limit-checks `< 0x21` (W26-F sealed) |
| SkyBoxParticles name | Prior scaffold alias | **Rejected** — sole xref is createRagDoll; plate on parent is `GameUtils::createRagDoll` |
| void return | analyze warning "undefined return" | **Rejected** — decompile returns `uVar1`; `MOV EDI,EAX` at caller |
| SEH-only / no real work | — | **Rejected** — five real callees; count path live |

---

## 2. Residual risks (non-blocking)

- `FUN_005f4230` decompile has stack-noise / unaff_ residuals — count math not OWN-sealed here.
- Container product types unknown.
- No runtime capture.

---

## 3. Cross-check vs A

A's CF table and ABI match live decompile + 155 B hex. Name `_Inferred` correctly marked.

---

## 4. Verdict

Adversarial pass **confirms** A: CF/ABI/caller/count sealed; nested parse residual only → **accept**.
