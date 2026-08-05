# Review A (reconstruction fidelity): `aa_0051a700` Skill_ClearCastBindingAndMaybeRestartCd

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a700` |
| **VA** | `0x0051a700` |
| **Canonical name** | `Skill_ClearCastBindingAndMaybeRestartCd` |
| **Review date** | `2026-07-23` (dual residual strengthen `2026-07-29`) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051a700_Skill_ClearCastBindingAndMaybeRestartCd.md` |
| **Residual scratch** | `reviews/a_0051a700.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Mutating** sibling of `Skill_LookupActiveCastBinding`: find active-cast map entry by **skillId**, erase it only when the node value matches a **partial TFID** (2 dwords + 1 byte), then optionally restart cast-again / CD via `Skill_StartCastAgainHeartbeat(owner, skill, chargeMs=0)` when the skill resolved by `owner.vtbl+0x234(skillId)` has **`skill+0x61c != 0`**.

Post-cast / status-apply cleanup — **not** LocalCastValidate, **not** host list clear (`Skill_SiblingCastClear` / `host+0xB0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051a700_Skill_ClearCastBindingAndMaybeRestartCd.md` |
| Annotated | `docs/reconstruction/raw/aa_0051a700_Skill_ClearCastBindingAndMaybeRestartCd.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ClearCastBindingAndMaybeRestartCd.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051a700_Skill_ClearCastBindingAndMaybeRestartCd.md` |
| Body bytes | PE `autoassault.exe` RVA `0x11a700` (file off `0x119b00`) — full body through `C2 14 00` |
| Map getter dual | `reviews/A\|B_aa_00518c20_FUN_00518c20.md` (leave-FUN, `owner+0x68`) |
| Exact find dual | `reviews/A\|B_aa_0051c150_Map_ExactFindByIntKey.md` (key `@node+0x10`) |
| Lookup dual | `reviews/A\|B_aa_00518cf0_Skill_LookupActiveCastBinding.md` (value TFID16 `@+0x18…+0x24`) |
| StartCastAgain dual | `reviews/A\|B_aa_00519200_*` + scratch `a_00519200.md` (call @ `0x0051a77c`) |
| Erase helper | `FUN_0051cb40` raw (`"invalid map/set<T> iterator"`) |
| Callers (clean/raw) | `Skill_ApplyStatusEffectLocal` @ binding cancel; `FUN_00578ce0` HB teardown |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`RET 0x14`** (exactly **5** stack dwords) | **Confirmed** | epilogue bytes `C2 14 00` |
| Signature: `(owner, skillId, tfid0, tfid1, tfid2, tfid3_u8pad)` | **High** | 5 stack formals; call sites pass skillId + Lookup TFID16 pack |
| Decomp names `(pSkill, nSkillId, nTfidLo, nTfidHi, bGlobal)` | **Falsified order/labels** | arg0=skillId key; arg1–3 = TFID match fields; arg4 unused in body |
| Map via `FUN_00518c20` (lazy `+0x68`) ×3 sites | **Confirmed** | call sites `0x0051a710`, `0x0051a71e`, `0x0051a74f` (sibling xref list) |
| Multi-arg `FUN_00518c20(pTmp,key)` | **Noise** | pushes stage `Map_ExactFindByIntKey` / erase; getter is unary |
| Find = `FUN_0051c150` @ `0x0051a717` | **Confirmed** | relative call + dual |
| End test `it != *(map+4)` | **Confirmed** | `cmp ecx,[eax+4]` / `je` skip erase |
| Match: `node+0x18==arg1`, `+0x1c==arg2`, `byte(+0x20)==arg3.lo` | **Confirmed** | body bytes; **partial** TFID (same 2+1 pattern as SiblingCastClear / Apply cancel) |
| Full 16-byte TFID equality in erase gate | **Falsified** | no compare of `node+0x24` / arg4 |
| arg4 (`tfid3` / decomp `bGlobal`) used in body | **Falsified** | never loaded after entry |
| Erase via `FUN_0051cb40` | **Confirmed** | call after map get; string "invalid map/set\<T\> iterator" |
| Erase gated on find **and** partial TFID match | **Confirmed** | fall-through skips erase on miss/mismatch |
| Restart arm **outside** erase gate | **Confirmed** | always runs after if-block |
| `owner.vtbl+0x234(skillId)` → skill runtime or null | **Confirmed** | `push skillId; call [vtbl+0x234]`; decomp zero-arg form **noise** |
| Gate `skill != 0 && *(u8*)(skill+0x61c) != 0` | **Confirmed** | `test eax; cmp byte [eax+0x61c],0` |
| `Skill_StartCastAgainHeartbeat(owner, skill, 0)` @ `0x0051a77c` | **Confirmed** | `push 0; push skill; mov ecx,owner; call` — sibling ABI `RET 0x8` |
| Always restarts CD | **Falsified** | gated on skill non-null **and** `+0x61c != 0` |
| Same polarity as RequestCast / ApplyStatus (`+0x61c==0` → start) | **Falsified as same policy** | Clear uses **inverted** gate (`!=0` → restart charge 0) — intentional per path table in `a_00519200` |
| Read-only / Lookup-only | **Falsified** | mutates map on match; may start HB |
| Range / power / LocalCastValidate | **Falsified** | no such logic |
| Host HB list clear (`+0xB0`) | **Falsified** | map at `FUN_00518c20`/`+0x68` only |
| Map owner product type | **Open** | leave-FUN sibling residual |
| Product English for `+0x61c` / vtbl+0x234 | **Open** | roles sealed High |

---

## 4. Control flow: clean ≡ raw ≡ body bytes

| Stage | Match |
|---|---|
| Prologue `push ecx; push esi; mov esi,ecx` (it slot + this) | **Yes** (bytes) |
| Stage key/it → `FUN_00518c20` → `FUN_0051c150` | **Yes** (noise on getter arity) |
| Second map get; `it == end` → skip erase | **Yes** |
| Partial TFID match → map get → `FUN_0051cb40` erase | **Yes** |
| `vtbl+0x234(skillId)` → `+0x61c` gate → StartCastAgain charge **0** | **Yes** |
| `pop esi; pop ecx; ret 0x14` | **Yes** |
| No invent power cost / wire / validate | **Yes** |

### Recovered CF (noise-corrected)

```c
// void __thiscall Skill_ClearCastBindingAndMaybeRestartCd(
//   void* owner,           // ECX
//   int   skillId,         // stack0 — map key
//   u32   tfid0,           // stack1 — node+0x18
//   u32   tfid1,           // stack2 — node+0x1c
//   int   tfid2,           // stack3 — only low byte vs node+0x20
//   char  tfid3_unused)    // stack4 — not read in body
// RET 0x14

void* map = FUN_00518c20(owner);              // unary leave-FUN @ +0x68
Map_ExactFindByIntKey(map, &it, &skillId);  // FUN_0051c150
map = FUN_00518c20(owner);
if (it != *(void**)(map + 4)
    && *(u32*)(it + 0x18) == tfid0
    && *(u32*)(it + 0x1c) == tfid1
    && *(u8*)(it + 0x20) == (u8)tfid2) {
  map = FUN_00518c20(owner);
  FUN_0051cb40(map, /*erase it*/);          // MSVC tree erase
}
// restart arm — NOT gated on erase success
void* skill = owner->vtbl[0x234/4](skillId);
if (skill != nullptr && *(u8*)(skill + 0x61c) != 0)
  Skill_StartCastAgainHeartbeat(owner, skill, /*chargeMs*/ 0);
```

---

## 5. Callers (inventory)

| Caller | Evidence | Args shape |
|---|---|---|
| `Skill_ApplyStatusEffectLocal` | raw/clean @ binding-cancel path | `caster`, `skill+0x5fc`, Lookup out TFID16 (4 stack words as 2+int+char pack) |
| `FUN_00578ce0` (skill HB teardown) | clean | owner derived from vtbl path; skillId `@HB+0x620`; TFID `@+0x678…+0x684` |

Lookup-then-clear pairing on status path: `Skill_LookupActiveCastBinding` fills TFID → Clear consumes same pack.

---

## 6. Gaps / open

1. Product type of map **owner** (`FUN_00518c20` / `+0x68` leave-FUN residual).
2. Product name / full schema of `FUN_0051cb40` erase (iterator packaging for third `FUN_00518c20` site).
3. Product English for **`vtbl+0x234`** (skill-by-id resolve) and **`skill+0x61c`** (defer / restart-pending bit — polarity inverted vs optimistic cast paths).
4. Whether arg4 is ABI padding only or used by other call-site contracts outside this body.
5. Live Ghidra MCP re-decompile this session **unavailable** — PE body bytes + sibling duals used as authority.
6. Runtime / bit-exact image-vs-load diff.

**Prior gaps closed this residual:** ABI `RET 0x14` / 5 stack formals; formal rename (skillId + partial TFID); erase vs restart separation; StartCastAgain charge **0** + `+0x61c != 0` polarity; decomp vtbl zero-arg / 4-arg StartCastAgain **noise**.

**Verdict:** **accept-with-gaps**
