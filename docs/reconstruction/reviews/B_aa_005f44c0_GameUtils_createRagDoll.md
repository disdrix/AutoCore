# Review B (skeptical / adversarial): `aa_005f44c0` GameUtils_createRagDoll

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f44c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-F) |
| **Counterpart** | `reviews/A_aa_005f44c0_GameUtils_createRagDoll.md` |
| **Scratch** | `tmp/a_005f44c0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a skybox particle helper | **Falsified** — plate strings name `GameUtils::createRagDoll`; prior SkyBox alias superseded |
| 2 | Always returns void | **Falsified** — EAX 0/1 at all exits |
| 3 | No param validation | **Falsified** — Body/world/buffer null gate + plate log |
| 4 | Unlimited bone counts | **Falsified** — hard caps `uVar4 < 0x21`, skeleton `< 0x41` |
| 5 | Name match is case-fold only | **Falsified** — also replaces `' '` with `'_'` in a loop |
| 6 | Success does not write owner | **Falsified** — stores `+0x50..+0x5c` (+ matrix `@+0x60` on root) |
| 7 | stdcall / RET n | **Falsified** — epilogue plain `RET` after `MOV ESP,EBP` |
| 8 | All nested callees sealed by this dual | **Overstated** — only this VA OWN; helpers residual |
| 9 | `FUN_00560e90(0)` path fully understood | **Residual Medium** — decompiler shows odd null arg; bytes may differ; not blocking plate CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Plate product name | **High** | Wrong system bucket only if ignored |
| Success/fail returns | **High** | Caller `@+0x90d` bit2 wrong |
| Limits 0x21 / 0x41 | **High** | Buffer OOB in port |
| Owner output offsets | **High** | Wrong ragdoll attach fields |
| Nested helper math | **Medium** | Partial port drift |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
if invalid params: log; return 0
init helpers; count = FUN_005f4380(p1,p2)
if count>=0x21 or skel>=0x41: fail
ensure vectors; alloc poses
for each body bone: normalize name; match; map parents; poses
if matched >= expected: build outs @+0x50..; return 1
else: log bones-not-found; return 0
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Sole caller `FUN_005911b0` toggles ragdoll flag bit from return.

---

## 4. Surviving contract for AutoCore

```
// Client ragdoll create (parity):
ok = GameUtils_createRagDoll(buffer, bufMeta, ownerCtx);
// ownerCtx+0x914 = gfx Body*; on success ownerCtx+0x50..+0x5c hold subsystems
// bone names: spaces become underscores before lookup
// enforce max 32 buffer bones and 64 skeleton entries
```

---

## 5. Verdict

Adversarial pass **confirms** A: plate name + CF/ABI/limits/outs sealed; nested helpers residual → **accept**.
