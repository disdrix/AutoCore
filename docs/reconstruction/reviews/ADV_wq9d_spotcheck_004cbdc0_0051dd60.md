# Independent adversarial spot-check — WQ9D-A dual `0x004cbdc0` + `0x0051dd60`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** WQ9D-A dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | WQ9D-A OWN pair (WQ-009 depth residual — skill-hash recreate/ctor) |
| **Units** | `0x004cbdc0` `SkillCNDHash_Recreate_Inferred`; `0x0051dd60` `SkillCNDHash_Ctor_Inferred` |
| **Tools** | Dual/report + A/B + raw/annotated/clean + function records + nested helper raw (`004cb410`/`004cba60`) + parent factory duals (`00518e30`) + prior independent ADV live decompile of these callees (`ADV_wq009_spotcheck_0051b550_00518e30.md`); inventory contrast `aa_004138d0` |
| **Live Ghidra this session** | MCP HTTP to `127.0.0.1:8089` **not reachable** from this ADV tool surface (localhost SSRF block; no MCP dispatch). Claims re-checked against sealed raw decompile + dual 2026-08-04 byte seals + parent ADV live `batch_decompile(0x004cbdc0,0x0051dd60)` |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-004cbdc0-0051dd60-wq9da-report.md` |
| `docs/reconstruction/reviews/A_aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0051dd60_SkillCNDHash_Ctor_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0051dd60_SkillCNDHash_Ctor_Inferred.md` |

### Artifacts (both units)

| Kind | `aa_004cbdc0` | `aa_0051dd60` |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_004cbdc0_FUN_004cbdc0.md` | `docs/reconstruction/raw/aa_0051dd60_FUN_0051dd60.md` |
| Annotated | `…/aa_004cbdc0_FUN_004cbdc0.annotated.md` | `…/aa_0051dd60_FUN_0051dd60.annotated.md` |
| Clean named | `…/SkillCNDHash_Recreate_Inferred.cpp` | `…/SkillCNDHash_Ctor_Inferred.cpp` |
| Clean twin | `…/FUN_004cbdc0.cpp` | `…/FUN_0051dd60.cpp` |
| Function named | `…/aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md` | `…/aa_0051dd60_SkillCNDHash_Ctor_Inferred.md` |
| Function FUN | `…/aa_004cbdc0_FUN_004cbdc0.md` | `…/aa_0051dd60_FUN_0051dd60.md` |

### Support / contrast evidence (not OWN duals)

| Artifact | Use |
|---|---|
| `raw/aa_004cb410_FUN_004cb410.md` | Mask post-condition: after alloc `*(+8)--` when `0 < log2 < 0x11` |
| `raw/aa_004cba60_FUN_004cba60.md` | Destroy path shape (zero `+0xc`, freelist helper, free slab/array) |
| `raw/aa_00518e30_FUN_00518e30.md` + A/B dual | Sole create caller; recreate ECX = `[owner+0x70]`; `new(0x34)` |
| `raw/aa_004138d0_FUN_004138d0.md` + A dual | Inventory recreate: **EAX/BL** custom ABI (contrast) |
| `ADV_wq009_spotcheck_0051b550_00518e30.md` | Prior independent live decompile of **both** OWN callees |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw 2026-07-23 decompile ≡ dual A CF tables | **Yes** (both units) |
| Dual re-verify 2026-08-04 claims live ≡ raw | Stated **identical**; body ends + entry/exit hex recorded |
| Clean named ≡ raw CF (lock continue; field stores; callees) | **Yes** |
| Clean twin ≡ named (Ghidra symbols) | **Yes** |
| Parent ADV live `batch_decompile(0x004cbdc0,0x0051dd60)` | Lock strings + continue; ctor vtbl `009ce1b8`, log2 `@+0x1c`, power-of-two at `+8` |
| Nested alloc raw mask | **`*(+8) = count - 1`** after bucket build — dual mask post-condition holds |
| Inventory ABI contrast | `004138d0`: `mov esi,eax` / BL log2 / bare `ret`; skill: thiscall ECX + stack log2 / `ret 4` |

---

## Unit A — `0x004cbdc0` SkillCNDHash_Recreate_Inferred

### Body / ABI seal (independent)

Body size arithmetic (inclusive end dual claim):

```text
0x004cbe14 − 0x004cbdc0 + 1 = 0x55 = 85 B
```

| Claim | Independent result |
|---|---|
| Range `0x004cbdc0`–`0x004cbe14` inclusive (**85 B** / `0x55`); `CC` pad after `ret 4` | **Confirmed** (dual re-verify end + size math; Ghidra end `004cbe14`) |
| **`__thiscall`**; entry `56 8B F1` (`push esi; mov esi,ecx`) | **Confirmed** (dual re-verify entry bytes; contrast inventory `56 8B F0` = EAX) |
| Stack log2 (byte width, dword push); cleanup **`ret 4`** (`5E C2 04 00`) | **Confirmed** (dual exit hex; raw has stack `param_2`) |
| Void (no EAX produce) | **Confirmed** (raw returns void; no `mov eax,esi`) |
| Lock `@+0x1d`: log `"HashError:Recreate, already locked for traversal"` + `"VOG_DEBUG_STOP"` then **continue** | **Confirmed** (raw: no early `return` after logs; parent ADV same) |
| Destroy `FUN_004cba60` then store log2 `@+0x1c`, zero `@+0x18`/`@+0x14`, provisional count `@+8 = 1<<(log2&0x1f)`, alloc `FUN_004cb410` | **Confirmed** (raw order exact) |
| Post-return `@+8` is **mask** `(1<<log2)-1` | **Confirmed via nested raw** `FUN_004cb410` line `*(param_1+8) = *(param_1+8) + -1` after building `n` buckets |
| Distinct from inventory `CNDHash_Recreate` `0x004138d0` | **Confirmed** — different VA, helpers (`004cba60`/`004cb410` vs `00413e20`/`00413d80`), **thiscall+stack** vs **EAX/BL** |
| Callers: CreateOrRecreateSkillHash + `FUN_004c8f00` (imm log2=2) | **Accepted** — parent dual seals recreate call with ECX=`[owner+0x70]`; dual B cites `0x004c902c` push 2 (second CODE site; not sole) |
| Name `_Inferred` / product English open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
void __thiscall FUN_004cbdc0(int param_1, byte param_2)
{
  if (*(char *)(param_1 + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Recreate, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    // fall through — no abort
  }
  FUN_004cba60();
  *(byte *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(int *)(param_1 + 8) = 1 << (param_2 & 0x1f);
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_004cb410();
  return; // ret 4
}
```

Clean `SkillCNDHash_Recreate_Inferred.cpp` matches this CF (lock continue; same field stores; same callees).

### Adversarial attacks (Recreate)

| # | Attack | Result |
|---|---|---|
| 1 | Same ABI as inventory `004138d0` (EAX/BL, bare ret) | **Fails** — thiscall ECX + stack log2 + `ret 4` |
| 2 | Lock aborts recreate / process | **Fails** — logs only; destroy/alloc still run |
| 3 | After return, `hash+8` remains bucket **count** | **Fails** — alloc decrements to **mask** |
| 4 | Stack arg is skill id / rank | **Fails** — drives `1<<log2` and store at `+0x1c` |
| 5 | Type-identity merge with inventory CNDHash | **Fails as identity** — shared string *family* only; different helpers/vtbl peer |
| 6 | Sole caller is CreateOrRecreateSkillHash | **Fails as sole** — second site `FUN_004c8f00` push 2 |
| 7 | ECX is owner object | **Fails** — factory loads `ECX=[owner+0x70]` before call |
| 8 | Soft no-op when locked | **Fails** — always tear-down + rebuild |
| 9 | Product class English sealed | **Fails** — `_Inferred` correct |
| 10 | Bit-exact / runtime Confirmed | **Fails** — open (dual owns) |

### Soft niggles (not sealed-claim failures)

1. **Nested destroy description (dual B):** B says destroy “zeros **count** field.” Raw `FUN_004cba60` zeros **`+0x0c`**, calls freelist helper, frees table — does **not** explicitly write `+0x08`. Recreate immediately overwrites `+0x08`, so OWN CF is unaffected. Support-only wording, not a dual verdict issue.
2. **Decompiler this-elision** on nested destroy/alloc when viewed from factory — same class of hazard parent ADV already documented for recreate ECX.
3. **log2 domain 1..16** is sealed on **callee** `FUN_004cb410` gate, not re-validated as OWN body branch (throw path lives in alloc).

### Unit A dual quality

**PASS** — keep **`accept-with-gaps`**.

Recreate CF, thiscall ABI, lock soft-continue, mask post-condition (via nested raw), and inventory ABI reject are independently consistent. Clean ≡ raw.

---

## Unit B — `0x0051dd60` SkillCNDHash_Ctor_Inferred

### Body / ABI seal (independent)

Body size arithmetic:

```text
0x0051ddd2 − 0x0051dd60 + 1 = 0x73 = 115 B
```

| Claim | Independent result |
|---|---|
| Range `0x0051dd60`–`0x0051ddd2` inclusive (**115 B** / `0x73`); `CC` pad after `ret 4` | **Confirmed** (size math + dual re-verify Ghidra end `0051ddd2`) |
| **`__thiscall`**; ECX = raw block; stack log2; **returns this in EAX**; **`ret 4`** | **Confirmed** (raw returns `param_1`; dual exit `mov eax,esi` + `ret 4`) |
| SEH `LAB_009a371b` | **Confirmed** (raw SEH locals; dual re-verify) |
| Vtbl install `PTR_FUN_009ce1b8` (`*this = 0x009ce1b8`) | **Confirmed** (raw `*param_1 = &PTR_FUN_009ce1b8`; clean stores constant) |
| `+0x08 = 1 << (log2 & 0x1f)` provisional count; byte `+0x1c = log2`; byte `+0x1d = 0` | **Confirmed** (raw exact) |
| Zeros: `+0x04`, `+0x0c`, `+0x10`, `+0x14`, `+0x18`, `+0x20`, `+0x28`, `+0x2c`, `+0x30` | **Confirmed** (raw indices `[1],[3],[4],[5],[6],[8],[10],[0xb],[0xc]`) |
| **`+0x24` not written** (skip between `[8]` and `[10]`) | **Confirmed** (raw omits `param_1[9]`; clean documents oddity) |
| Post-init `FUN_004cb410` → mask at `+8` when log2 in range | **Confirmed** (same nested alloc raw) |
| sizeof **0x34** via sole create caller `new(0x34)` | **Confirmed** (factory raw `operator_new(0x34)`) |
| Sole CODE caller `FUN_00518e30` create path → store `owner+0x70` | **Confirmed** (factory raw; parent dual xrefs for factory, not multi-direct ctor) |
| Name `_Inferred` / product English open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
undefined4 * __thiscall FUN_0051dd60(undefined4 *param_1, byte param_2)
{
  // SEH LAB_009a371b
  *param_1 = &PTR_FUN_009ce1b8;
  param_1[1] = 0;  param_1[3] = 0;
  param_1[2] = 1 << (param_2 & 0x1f);
  param_1[4] = 0;  param_1[5] = 0;  param_1[6] = 0;
  *(byte *)(param_1 + 7) = param_2;
  *(undefined1 *)((int)param_1 + 0x1d) = 0;
  param_1[8] = 0;
  // +0x24 skipped
  param_1[10] = 0;  param_1[0xb] = 0;  param_1[0xc] = 0;
  FUN_004cb410();
  return param_1; // EAX = this; ret 4
}
```

Clean `SkillCNDHash_Ctor_Inferred.cpp` matches field map and intentional `+0x24` skip.

### Adversarial attacks (Ctor)

| # | Attack | Result |
|---|---|---|
| 1 | Void ctor (no return) | **Fails** — returns this; factory stores EAX |
| 2 | Allocates its own memory | **Fails** — placement on ECX; caller `operator_new(0x34)` |
| 3 | sizeof is skill runtime object (~0x630) | **Fails** — hash header **0x34** only |
| 4 | log2 is skill id | **Fails** — size exponent for bucket count |
| 5 | Multi-caller fan-in on this VA | **Fails** — sole sealed code xref is create path of `00518e30` |
| 6 | Same type as inventory CNDHash ctor | **Fails** — vtbl `009ce1b8` skill family |
| 7 | Zeros entire `0x34` block | **Fails** — **`+0x24` unwritten** |
| 8 | Sets traversal lock true | **Fails** — `+0x1d = 0` |
| 9 | Product name sealed | **Fails** — `_Inferred` |
| 10 | Bit-exact complete | **Fails** — open |

### Soft niggles (not sealed-claim failures)

1. **SEH frame omitted in clean** — dual A documents; behavior-preserving CF correct.
2. **Full vtbl method map** / RTTI string for `009ce1b8` open (docs residual).
3. **Semantics of unwritten `+0x24`** (pad vs latent) open — correctly not invented as zero store.

### Unit B dual quality

**PASS** — keep **`accept-with-gaps`**.

Ctor CF, return-this ABI, vtbl, sizeof 0x34, field layout including `+0x24` skip, and sole create caller relationship are independently consistent. Clean ≡ raw.

---

## Cross-unit consistency

| Topic | Independent |
|---|---|
| Pair relationship | **Confirmed** — create path ctor `0051dd60`; recreate path `004cbdc0`; shared alloc `004cb410` |
| Shared field map | log2 `@+0x1c`, lock `@+0x1d`, provisional count then mask `@+8`, ordered head/tail `@+0x14`/`@+0x18` |
| Owner slot | Factory stores/loads skill hash at **`owner+0x70`** |
| Vtbl peer | Ctor installs `009ce1b8`; recreate assumes existing object (does not re-store vtbl) |
| Inventory contrast | Skill uses **thiscall+stack+ret4**; inventory sheet family uses **EAX/BL** at `004138d0` |
| Chain | trio/orphan → `CreateOrRecreateSkillHash` → OWN recreate **or** ctor |
| Second recreate caller | `FUN_004c8f00` log2=2 (not via factory) — dual correctly does not claim sole recreate caller |
| Naming | Both `_Inferred`; scaffold/VOG string aliases correctly not promoted |

```text
Object_CreateOrRecreateSkillHash_Inferred (0x00518e30)
  ├─ existing +0x70 → SkillCNDHash_Recreate_Inferred (0x004cbdc0)  [OWN]
  └─ missing → new(0x34) + SkillCNDHash_Ctor_Inferred (0x0051dd60) [OWN]
FUN_004c8f00 also → Recreate (log2=2)
```

---

## Confirmations

1. WQ9D-A dual A/B + agent report seals for both VAs are **faithful** to raw decompile, nested alloc mask math, factory caller context, and prior independent ADV live decompile of these exact addresses.
2. Recreate: lock soft-log-then-continue, thiscall ECX=hash, stack log2, `ret 4`, destroy→resize fields→alloc — **confirmed**.
3. Ctor: vtbl `009ce1b8`, sizeof 0x34, return this, skip `+0x24`, sole create caller — **confirmed**.
4. Dual B correctly rejects inventory ABI merge, owner-as-this, soft-abort-on-lock, skill-id-as-log2, void-ctor, and full-block-zero claims.
5. Clean named sources match raw semantics; twins keep Ghidra symbols.
6. Product English residual correctly leaves `_Inferred`; terminal false.

---

## Gaps (remain open — dual already owns)

| Gap | Unit | Blocks accept? |
|---|---|---|
| Product / PDB class name for skill CNDHash (`vtbl 009ce1b8`) | Both | No (`accept-with-gaps`) |
| Full dual of nested `FUN_004cba60` / `FUN_004cb410` | Both (support) | No |
| Bit-identity of freelist/node layout vs inventory CNDHash | Recreate family | No |
| Semantics of unwritten `+0x24` | Ctor | No |
| Full vtbl method map / RTTI string | Ctor | No |
| Scalar dtor peer `FUN_0051de60` dual | Ctor adjacent | No |
| Runtime / bit-exact / differential | Both | No (policy; terminal false) |

---

## Pass / fail

| Unit | Dual verdict | ADV result |
|---|---|---|
| `0x004cbdc0` SkillCNDHash_Recreate_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x0051dd60` SkillCNDHash_Ctor_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |

### Overall

**PASS** — WQ9D-A dual seals hold under independent multi-source verification (raw + dual byte seals + nested helper raw + factory duals + prior ADV live decompile of both OWN VAs). No sealed-claim failure requiring dual rewrite or verdict downgrade.

Soft niggle only: dual B’s nested destroy “zeros count” wording is imprecise vs raw `+0x0c` zero (not `+0x08`); does not touch OWN recreate CF.

**terminal = false**

---

## Process notes

- Independent ADV verifier; **not** WQ9D-A author.
- **No** parent ledger / WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY edits.
- **No** dual A/B rewrite; **no** Launcher.
- Live Ghidra MCP not callable from this ADV session tool surface; verification uses sealed raw, dual re-verify byte claims, nested helper raw, factory duals, and prior independent ADV live `batch_decompile` of `0x004cbdc0`/`0x0051dd60`.
- Output: `docs/reconstruction/reviews/ADV_wq9d_spotcheck_004cbdc0_0051dd60.md` (this file).
