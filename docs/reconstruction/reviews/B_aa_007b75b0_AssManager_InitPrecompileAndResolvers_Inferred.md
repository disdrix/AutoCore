# Review B (skeptical / adversarial): `aa_007b75b0` AssManager_InitPrecompileAndResolvers_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b75b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-D) |
| **Counterpart** | `reviews/A_aa_007b75b0_AssManager_InitPrecompileAndResolvers_Inferred.md` |
| **Scratch** | `tmp/a_007b75b0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this | **Falsified** — stdcall stack formals; **`RET 8`** |
| 2 | Always registers both resolvers | **Falsified** — gated on `self+0x04` bits 0/1 |
| 3 | Both inserts use PushBackLocked | **Falsified** — A uses `0043c4f0`; B inlines host CS + raw `0043c830` |
| 4 | Duplicate always soft-fails | **Falsified** — A soft log; B may `ExitProcess(3)` |
| 5 | List at host+0x00 | **Falsified** — **host+0x58** (matches RemoveResolver) |
| 6 | Product name retail | **Overstated** — inferred from plates + CF |
| 7 | `FUN_00984ee0` fully understood | **Open** — unowned; count/mode sealed only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 8 + 2 stack formals | **High** | Stack tear |
| Path/precompile stages | **High** | Wrong FS layout |
| Flag bits + resolver slots | **High** | Leaks / double-free with ReleaseOwned |
| host+0x58 insert A/B | **High** | Wrong list / lock |
| Dual insert lock styles | **High** | Deadlock if unified wrongly |
| Product English | **Inferred** | Naming only |
| Nested helper free | **Open** | Port gaps |
| Runtime / FS | **Open** | Env-dependent |

---

## 3. Cross-check against raw + bytes

```
raw / live ≡ 2026-07-23 scaffold CF (re-verified 2026-07-29)

entry: SEH + SUB ESP,0x44 + string "../effects"
epilogue: ADD ESP,0x50; RET 8

A-insert site:
  MOV EDI,[DAT_00d1f058]; ADD EDI,0x58
  find FUN_0043e5b0; miss → CALL 0043c4f0

B-insert site:
  host CS via [host+0x84] / host+0x6c
  CALL 0043c830 (raw PushBack)
```

String constants verified via `read_memory` (effects path, precompile, mkdir fail, duplicate resolver).

Callers: client init `00948bd0` passes `FUN_007b6a20()` object + mode `1` before window registration — bootstrap role confirmed.

---

## 4. Surviving contract for AutoCore

```
// AssManager client bootstrap:
//   stdcall (self*, mode); RET 8
//   ensure ../effects[/precompile] (or ".")
//   publish path; host+0xd0=1; side inits
//   if flags&1: new A @ self+8; unique-push host+0x58 via PushBackLocked
//   if flags&2: new B @ self+0xc; unique-push under host CS + raw PushBack
//   do not unify A/B lock styles; do not treat duplicates identically
//   pair with ReleaseOwnedResolvers for self+8/+0xc teardown
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/path/flag/list/insert polarity; nested free + product residual → **accept-with-gaps**.
