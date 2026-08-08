# Independent adversarial spot-check — WQ9G free-subtree + complete dtor

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** dual author for WQ9G-A / WQ9G-G) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth4_partition_map.md` → sample of **WQ9G-A** + clone free from **WQ9G-G** |
| **Units** | (1) `0x004cb550` `StdTree_FreeSubtree_Isnil29_Inferred` |
| | (2) `0x0051de80` `SkillCNDHash_CompleteDtor_Inferred` |
| | (3) `0x00406c00` `StdTree_FreeSubtree_Isnil29_Inferred` (clone VA) |
| **Tools** | Dual reports + A/B + raw/annotated/clean + function records; dual-appended `read_memory` full-body hex; body-size arithmetic; rel32 call-target math; peer free family (`Map_FreeSubtree_Isnil29` / range parents). **No** `disassemble_bytes` |
| **Live Ghidra this session** | Not required for seal — dual re-verify 2026-08-04 documents live decompile ≡ raw scaffold + full-body hex; independent re-check uses those sealed surfaces + arithmetic on appended bytes |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** (no runtime Confirmed) |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-004cb550-0051de80-wq9ga-report.md` |
| `docs/agents/task-dual-ab-004cba00-00406c00-wq9gg-report.md` (free unit only for this ADV) |
| `docs/reconstruction/reviews/A_aa_004cb550_StdTree_FreeSubtree_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004cb550_StdTree_FreeSubtree_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0051de80_SkillCNDHash_CompleteDtor_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0051de80_SkillCNDHash_CompleteDtor_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00406c00_StdTree_FreeSubtree_Isnil29_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00406c00_StdTree_FreeSubtree_Isnil29_Inferred.md` |

### Artifacts (three VAs)

| Kind | `aa_004cb550` | `aa_0051de80` | `aa_00406c00` |
|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_004cb550_FUN_004cb550.md` | `raw/aa_0051de80_FUN_0051de80.md` | `raw/aa_00406c00_FUN_00406c00.md` |
| Annotated | `…FUN_004cb550.annotated.md` | `…FUN_0051de80.annotated.md` | `…FUN_00406c00.annotated.md` |
| Clean named (claimed) | `StdTree_FreeSubtree_Isnil29_Inferred.cpp` | `SkillCNDHash_CompleteDtor_Inferred.cpp` | `StdTree_FreeSubtree_Isnil29_Inferred.cpp` ⚠️ |
| Clean twin | `FUN_004cb550.cpp` | `FUN_0051de80.cpp` | `FUN_00406c00.cpp` ⚠️ |
| Function named | `aa_004cb550_StdTree_…` | `aa_0051de80_SkillCNDHash_…` | `aa_00406c00_StdTree_…` |

⚠️ = **material artifact finding** (see Unit C): shared short clean path is owned by **`0x004cb550`**; `0x00406c00` duals/records claim the same path and thin-wrap into it.

### Peer / chain evidence (not OWN duals of this ADV)

| Artifact | Use |
|---|---|
| Dualed `StdTree_EraseRange_Isnil29_Inferred` (`0x004cbaa0`, WQ9F-C) | Sole external caller of free `004cb550` on full-clear |
| Dualed `Map_FreeSubtree_Isnil29` (`0x0051bbc0`, WQ9E-H) clean | CF twin of both free clones; distinct EraseRange pair / VA |
| Dualed `SkillCNDHash_ScalarDeletingDtor_Inferred` (`0x0051de60`, WQ9F-H) | Sole code caller of complete dtor `0051de80` |
| Dualed `SkillCNDHash_DestroyBucketTable_Inferred` (`0x004cba60`, WQ9E-A) | Nested teardown callee of complete dtor |
| Prior ADV `ADV_wq9e_spotcheck_ui_erase.md` | Family hazard: un-suffixed clean collision across isnil29 clones |
| Prior ADV `ADV_wq9f_spotcheck_map_erase.md` | Family free algebra / false-noreturn delete pattern |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw 2026-07-23 decompile ≡ dual A CF tables (modulo free left-walk gap) | **Yes** — free decomp incomplete as duals claim; dtor decomp matches |
| Dual re-verify 2026-08-04: live ≡ raw + full-body hex | Stated **identical** for free incompleteness + dtor CF |
| Body-size arithmetic on inclusive ranges | **Yes** (see units) |
| Free clone hex: only `operator_delete` rel32 differs | **Yes** — independent byte diff |
| Free rel32 self-call / delete targets | **Yes** — self; both deletes → same CRT site `0x00489822` |
| Complete dtor rel32 → `004cba60` / `0059c8a0` | **Yes** |
| Clean named path owns claimed VA (no collision) | **No** for free short name (see Unit C) |
| isnil29 free ≠ Map free `0051bbc0` by VA/callers | **Yes** |
| Terminal false honesty | **Yes** (both dual reports + this ADV) |

---

## Unit A — `0x004cb550` StdTree_FreeSubtree_Isnil29_Inferred (WQ9G-A)

### Body / ABI / CF seal (independent)

```text
0x004cb584 − 0x004cb550 + 1 = 0x35 = 53 B inclusive
```

Full-body hex count from dual A / raw re-verify = **53 B**. Terminal `C2 04 00`; pad `CC`.

| Claim | Independent result |
|---|---|
| Body `0x004cb550`–`0x004cb584` inclusive (**53 B**); **`ret 4`** | **Confirmed** — size math + hex epilogue |
| ECX = tree_base threaded (`MOV EBX,ECX` / recursive `MOV ECX,EBX`); stack `node*` | **Confirmed** — entry `53 56 57 8B 7C 24 10` + `8B D9` / `8B CB` |
| isnil@**+0x29** gate (`80 7F 29 00` / `80 7E 29 00`) | **Confirmed** — hex immediates |
| Right recurse `@+8` (`8B 46 08; PUSH; CALL self`) | **Confirmed** — self rel32: `E8` @ `0x004cb567` → next `0x004cb56c` + `0xFFFFFFE4` = **`0x004cb550`** |
| Left walk `@+0` (`8B 36`) + loop (`74 E2`) after `ADD ESP,4` | **Confirmed** — bytes authority; **decomp omits** (raw plate incomplete) |
| `operator_delete` cdecl continues (`PUSH; CALL; ADD ESP,4`) — **not** noreturn | **Confirmed** — `83 C4 04` then isnil recheck |
| Delete target | **Confirmed** — `E8` @ `0x004cb56f` → next `0x004cb574` + signed `0xFFFBE2AE` = **`0x00489822`** |
| No value / vtbl destroy | **Confirmed** — no payload load in body hex |
| Sole external caller `StdTree_EraseRange_Isnil29` full-clear (`0x004cbaa0` @ `0x004cbabc`) | **High** — dual xrefs; peer range dual (WQ9F-C / ADV_wq9f) wires `FUN_004cb550(head->parent)` |
| Distinct from `Map_FreeSubtree_Isnil29` @ `0x0051bbc0` | **Confirmed** — different VA + EraseRange free pair |
| Product demangle / value_type | **Open** — `_Inferred` correct |
| Runtime / bit-exact | **Open** — Terminal false |

### Decompile vs bytes (family hazard)

Raw / live decompile collapses to right-only recurse + false noreturn on delete. Dual A/B correctly promote **bytes** for left spine. Clean `StdTree_FreeSubtree_Isnil29_Inferred.cpp` restores the left-walk loop and is **owned by this VA** (header `aa_004cb550` / sole EraseRange caller note).

### Adversarial attacks (free `004cb550`)

| # | Attack | Result |
|---|---|---|
| 1 | Decompiler body is complete | **Fails** — left walk + continue after delete sealed by hex |
| 2 | Bare cdecl `void(node*)` only | **Fails** — ECX threaded + **`ret 4`** |
| 3 | Destroys `T*` values | **Fails** — delete node only |
| 4 | Frees isnil sentinel | **Fails** — gate returns without delete |
| 5 | Identity merge with `Map_FreeSubtree_Isnil29` (`0x0051bbc0`) | **Fails** — twin CF, distinct VA/callers |
| 6 | Identity merge with free `0051be90` / Val12 / isnil15 | **Fails** — isnil@+0x29 + this EraseRange pair |
| 7 | Product name from VOG_DEBUG_STOP scaffold | **Fails** — role from CF + EraseRange |
| 8 | Runtime Confirmed | **Fails** |

### Soft niggles

1. Dual B “sole EraseRange pair” is correct for **this** clone; does not list peer free clone `0x00406c00` (same short name) — registry hygiene residual (see Unit C / rollup).
2. Shared short clean name is **correctly owned** by this VA today; risk is downstream merge treating it as the only isnil29 free body in the image.

### Unit A dual quality

**PASS** — keep **`accept-with-gaps`**. CF/ABI/bytes seals hold; clean plate matches this VA.

---

## Unit B — `0x0051de80` SkillCNDHash_CompleteDtor_Inferred (WQ9G-A)

### Body / ABI / CF seal (independent)

```text
0x0051deea − 0x0051de80 + 1 = 0x6B = 107 B inclusive
```

Full-body hex count from dual A / raw re-verify = **107 B**. Terminal bare **`C3`**; pad `CC`. Immediately after scalar dtor `0x0051de60`–`0x0051de7d`.

| Claim | Independent result |
|---|---|
| Body **107 B**; bare **`ret`** | **Confirmed** — size math + hex `C3` |
| **`__thiscall`** ECX=this; no stack args | **Confirmed** — `56 8B F1` + bare `C3` (raw `__fastcall` label is decomp flavor only) |
| SEH frame `LAB_009a371b` | **Confirmed** — entry `6A FF 68 1B 37 9A 00 64 …` |
| Vtbl reinstall `PTR_FUN_009ce1b8` | **Confirmed** — `C7 06 B8 E1 9C 00` |
| Soft lock `@+0x1d`: log then **continue** | **Confirmed** — `80 7E 1D 00` / `74 1B` over two log calls then fall through |
| Strings | **High** — dual sealed `"HashError:Destructor…"` @ `0x00a2c270`, `"VOG_DEBUG_STOP"` @ `0x00a15844`; push immediates match hex |
| `SkillCNDHash_DestroyBucketTable` (`0x004cba60`) | **Confirmed** — `E8` @ `0x0051dece` → next `0x0051ded3` + signed `0xFFFADB8D` = **`0x004cba60`** |
| Freelist/slab host teardown `FUN_0059c8a0` with **`this+0x20`** | **Confirmed** — `8D 4E 20` then `E8` @ `0x0051ded6` → next `0x0051dedb` + `0x0007E9C5` = **`0x0059c8a0`** |
| Does **not** free host | **Confirmed** — no `operator_delete(this)`; bare ret |
| Sole code caller scalar dtor `0x0051de60` @ `0x0051de63` | **High** — dual xrefs; scalar dual WQ9F-H residual closed by this wave |
| vtbl[0] is scalar, not this complete body | **High** — dual DATA seal; MSVC complete/scalar split |
| Product English class name | **Open** — `_Inferred` correct |
| Full dual of `0059c8a0` | **Open** — not OWN; fair gap |
| Runtime / bit-exact | **Open** |

### Live decompile (raw plate summary)

```c
void __fastcall FUN_0051de80(undefined4 *self)  // thiscall in practice
{
  // SEH LAB_009a371b
  *self = &PTR_FUN_009ce1b8;
  if (*(char *)((int)self + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:Destructor, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    // fall through
  }
  FUN_004cba60();              // ECX=self (bytes)
  FUN_0059c8a0();              // ECX=self+0x20 (bytes LEA)
  return;                      // bare ret
}
```

Named clean matches CF with explicit `+0x20` and soft-lock continue. Twin `FUN_0051de80.cpp` is a thinner but consistent surface.

### Adversarial attacks (complete dtor)

| # | Attack | Result |
|---|---|---|
| 1 | This VA is the scalar deleting dtor | **Fails** — scalar `0x0051de60` / vtbl[0]; this is complete body callee |
| 2 | Lock aborts / noreturn | **Fails** — log then destroy + freelist teardown |
| 3 | Frees host with `operator_delete` | **Fails** — bare `C3`; free only in scalar when `flags&1` |
| 4 | Inventory CNDHash dtor identity | **Fails** — skill vtbl `009ce1b8` + HashError string family |
| 5 | `FUN_0059c8a0` with bare `this` | **Fails** — `LEA ECX,[ESI+0x20]` |
| 6 | Stack args / `ret 4` | **Fails** — no stack args; bare ret |
| 7 | DestroyBucketTable is entire dtor | **Fails** — freelist host teardown follows |
| 8 | Runtime Confirmed | **Fails** |

### Soft niggles

1. Named clean embeds a `FUN_0051de80` wrapper **and** a separate twin file exists — redundant, not a seal failure.
2. Freelist host algebra of `0059c8a0` remains residual — dual correctly open.

### Unit B dual quality

**PASS** — keep **`accept-with-gaps`**.

---

## Unit C — `0x00406c00` StdTree_FreeSubtree_Isnil29_Inferred (WQ9G-G clone)

### Body / ABI / CF seal (independent)

```text
0x00406c34 − 0x00406c00 + 1 = 0x35 = 53 B inclusive
```

Full-body hex count = **53 B**. Terminal `C2 04 00`; pad `CC`.

| Claim | Independent result |
|---|---|
| Body 53 B; ECX threaded; stack node*; **`ret 4`** | **Confirmed** — same prologue/epilogue shape as Unit A |
| isnil@+0x29 / right@+8 / left@+0 free algebra | **Confirmed** — hex identical to Unit A except delete rel32 |
| Decompiler incomplete (false noreturn; missing left walk) | **Confirmed** — raw ≡ Unit A decomp shape |
| External callers: `FUN_00407d70`, `FUN_0092f3b0`, `FUN_009463b0` (+ self) | **High** — dual re-verify table; multi-caller vs Unit A sole EraseRange |
| Twin CF `Map_FreeSubtree_Isnil29` (`0x0051bbc0`) — do not merge | **Confirmed** — dual B + peer clean |
| Self-call rel32 | **Confirmed** — same `E8 E4 FF FF FF` layout as Unit A → self |
| Delete target | **Confirmed** — `E8` @ `0x00406c1f` → next `0x00406c24` + `0x00082BFE` = **`0x00489822`** (same CRT as Unit A) |
| Product value_type / range parent dual | **Open** — fair |
| Runtime / bit-exact | **Open** |

### Byte identity vs Unit A (independent)

| Region | `004cb550` | `00406c00` |
|---|---|---|
| Prologue through self-call | **Identical** | **Identical** |
| `operator_delete` rel32 | `AE E2 FB FF` | `FE 2B 08 00` |
| Post-delete left-walk + epilogue | **Identical** | **Identical** |
| Resolved delete | `0x00489822` | `0x00489822` |

Control shape is a true **clone** (same CRT delete, different call-site rel32). Dual “CF twin of `0051bbc0`” is accurate; **peer clone is also `004cb550`** — duals under-document that peer.

### Clean-path collision (material)

Both duals / function records promote the **same** short name and claim clean:

```text
docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil29_Inferred.cpp
```

Independent read of that file:

| Field | Value |
|---|---|
| Stable ID in header | **`aa_004cb550`** |
| Address in header | **`0x004cb550`–`0x004cb584`** |
| Caller note | Sole external: **StdTree_EraseRange** full-clear |

So the un-suffixed clean is **Unit A’s plate**, not Unit C’s.

Further artifact state:

| Path | Problem |
|---|---|
| `FUN_00406c00.cpp` | Thin-wraps into `StdTree_FreeSubtree_Isnil29_Inferred` (Unit A symbol) |
| Function record `aa_00406c00_*` | Lists named clean as the shared short path |
| `StdTree_FreeSubtree_Isnil29_00406c00_Inferred.cpp` | Claimed VA-suffix **does not own a body** — still wraps to the shared short symbol / copies FUN twin wrapper |
| Dual report WQ9G-G file table | Claims Clean = shared short path |

This is the same family of failure as prior ADV on insert clones (`ADV_wq9e_spotcheck_ui_erase.md`): **shared structural name + single un-suffixed clean path can hold only one VA**.

**Impact:** AutoCore porting or parent merge that trusts the clean path for `aa_00406c00` would wire the **EraseRange free residual** (`004cb550`) rather than a plate that owns **range parent `00407d70` / Phy reinit callers**. Dual **raw + A/B CF** for `0x00406c00` remain correct.

**Recommended parent/dual follow-up (not done by this ADV):**

1. Emit a true VA-disambiguated clean body for `0x00406c00` (e.g. `StdTree_FreeSubtree_Isnil29_00406c00_Inferred.cpp` with own stable ID/address/caller notes — not a wrapper to the short name).
2. Optionally rename/keep `…_004cb550_Inferred.cpp` as the VA-suffixed peer of Unit A; keep short name as alias **or** retire short name to one primary with explicit peer list.
3. Fix `aa_00406c00` function records + dual report file table + `FUN_00406c00.cpp` redirect.
4. Cross-link both free clones + `Map_FreeSubtree_Isnil29` (`0051bbc0`) in NAMING_REGISTRY peer list (do not merge VAs).

### Adversarial attacks (free `00406c00`)

| # | Attack | Result |
|---|---|---|
| 1 | Decompiler body is complete | **Fails** — left walk sealed by hex |
| 2 | Bare cdecl only | **Fails** — ECX + **ret 4** |
| 3 | Value destroy | **Fails** |
| 4 | Bit-identical merge with `0051bbc0` as one symbol | **Narrow** — CF twin; **distinct VA** / callers |
| 5 | Val12 free (isnil@+0x19) | **Fails** — isnil@+0x29 |
| 6 | Mission-notify scaffold product name | **Fails** — structural free |
| 7 | Same as `Map_FreeSubtree_B` / Unit A as one **code** site | **Fails** — distinct VAs; Unit A sole EraseRange caller differs |
| 8 | Clean plate at claimed path is authoritative for this VA | **Succeeds as attack** — plate is **`004cb550`** |
| 9 | Runtime Confirmed | **Fails** |

### Unit C dual quality

**PASS-WITH-FINDINGS** — keep dual verdict **`accept-with-gaps`** for **CF/ABI seals** (raw + A/B + hex), but **reject the clean-path claim** until a VA-disambiguated clean owns `0x00406c00`.

---

## Cross-unit dual report quality

| Check | WQ9G-A free | WQ9G-A dtor | WQ9G-G free clone |
|---|---|---|---|
| Dual report verdicts match A/B | **Yes** — accept-with-gaps | **Yes** | **Yes** |
| Terminal false honesty | **Yes** | **Yes** | **Yes** |
| OWN scope discipline | **Yes** | **Yes** | **Yes** (free half of WQ9G-G) |
| Tool discipline | **Yes** — no `disassemble_bytes` | **Yes** | **Yes** |
| Decompiler artifact honesty | **Yes** — false noreturn + missing left walk | **Yes** — soft-lock continue; thiscall | **Yes** |
| Odd behavior preserved | left-walk / noreturn | lock soft-log continue | left-walk / noreturn |
| Clean sources meaningful | **Yes** (owns short plate) | **Yes** | **No** — short path collision |
| Peer non-merge hygiene | ≠ Map free `0051bbc0` | ≠ scalar / inventory | ≠ Map free; **misses peer free `004cb550` in dual text** |
| AutoCore port notes | Accurate free algebra | Accurate complete dtor contract | Accurate CF; **clean path unsafe for `00406c00`** |

### Independent overall verdict

| Unit | Dual verdict | ADV verdict |
|---|---|---|
| `aa_004cb550` StdTree_FreeSubtree_Isnil29_Inferred | accept-with-gaps | **PASS — keep accept-with-gaps** |
| `aa_0051de80` SkillCNDHash_CompleteDtor_Inferred | accept-with-gaps | **PASS — keep accept-with-gaps** |
| `aa_00406c00` StdTree_FreeSubtree_Isnil29_Inferred | accept-with-gaps | **PASS-WITH-FINDINGS** — CF seals hold; **clean plate mis-bound to `0x004cb550`** |

### Spot-check rollup

**Overall WQ9G free/dtor ADV: PASS-WITH-FINDINGS.**

- **WQ9G-A free `004cb550`:** fully seals under independent review; owns short clean plate; keep accept-with-gaps.
- **WQ9G-A complete dtor `0051de80`:** fully seals under independent review (vtbl / soft-lock continue / teardown order / callee rel32 math); keep accept-with-gaps.
- **WQ9G-G free clone `00406c00`:** dual **raw/A/B CF** seals (53 B clone of free algebra; multi-caller); **artifact hygiene fails** on shared clean filename collision with WQ9G-A `0x004cb550` (and incomplete VA-suffix stub still wraps short name). Parent merge must not treat `StdTree_FreeSubtree_Isnil29_Inferred.cpp` as the `0x00406c00` body until disambiguated.

**No dual rewrite performed by this ADV** (per charter). Terminal remains **false**.

---

## Process

- Independent ADV verifier; **not** WQ9G-A / WQ9G-G dual author.
- Evidence: dual reports, A/B, raw/annotated/clean/function records; dual-appended full-body hex; independent size + rel32 arithmetic; peer free/dtor chain duals + prior ADV collision pattern.
- **No** `disassemble_bytes`. **No** parent ledger edits. **No** dual file edits. **No** Launcher.
- Output: `docs/reconstruction/reviews/ADV_wq9g_spotcheck_free_dtor.md` (this file).

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
