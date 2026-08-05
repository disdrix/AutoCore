# Review A (reconstruction fidelity): `aa_004d5c10` Mission_ProcessInteractOfferStaging

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d5c10` |
| **VA** | `0x004d5c10` |
| **Canonical name** | `FUN_004d5c10` (proposed: `Mission_ProcessInteractOfferStaging`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-O) |
| **Counterpart** | `reviews/B_aa_004d5c10_Mission_ProcessInteractOfferStaging.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Mission interact offer / turn-in staging** for a multi-TFID interact block:

1. SEH + resolve **interact target** from `param_1[1]` COID pair; alloc empty list (`FUN_0040fb90`).
2. Resolve **subject object** from `param_1`; `character = vtbl+0x210(0)`; fail → cleanup.
3. **`FUN_0052d8b0(character, 0, -1)`** — full mission staging clear (map-only).
4. If target non-null and **`*(target+0xa8)+0x38 == 0x3a`**:
   - Optional linked-object vector (`target+0x1d8`) may set `*param_2`.
   - If `*param_2`: walk active missions; match staging `+0x20/+0x24` to NPC CBID/continent; `FUN_0052c700` + turn-in ready → payload `+0x2c`.
   - Build offerable mission pointer vector from `target+0x234` **or** `+0x244` **or** continent table; gates = not active, requirements OK, completed/reoffer rules.
   - For each selected def: stamp staging CBID/continent/`+0x28`; **`FUN_004d08c0(def, character, param_3)`**.
5. Else (non-0x3a): `Lookup(char[0x152], key)`; **`FUN_004cf100`** type-0 rewards; set `*param_2` from `param_1+2` resolve; patch ready byte.

Sibling eval-only: `0x004d5aa0` (returns 6/7). This unit **writes staging + reward slots**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004d5c10` (2026-07-29) ≡ raw |
| Entry / epilogue | `read_memory` @ `0x004d5c10`, `0x004d6140`, `0x004d64b8` — SEH + **`ret 0xC`** |
| Xrefs / callees | `analyze_function_complete` — 1 xref `0x009245e6`; callees listed in fn record |
| Call site | `read_memory` @ `0x009245d8` — 3 pushes before call |
| Staging duals | `A_aa_0052d8b0`, `A_aa_0052c700`, `A_aa_0052dac0`, `A_aa_0052b420` |
| Reward duals | `A_aa_004d08c0`, `A_aa_004cf100` |
| Raw / annotated / clean | updated scaffold + stamp |

**Not performed:** Launcher, runtime, bit-exact, `disassemble_bytes`, dual of sole caller body.

---

## 3. Signature (image-sealed)

```c
// ret 0xC
void Mission_ProcessInteractOfferStaging(
    TFID_16 *pTfidBlock,  // EBX from [esp+arg]; [1] = interact COID; [0] resolve subject
    int *pOutIdentity,    // written on several success paths
    uint32_t rollOrCtx);  // forwarded to FUN_004d08c0 as 3rd arg
```

| Claim | Evidence | Conf |
|---|---|---|
| 3 stack formals / `ret 0xC` | Epilogue `C2 0C 00`; call site 3 pushes | **Confirmed** |
| SEH frame | `push -1; push LAB_009a2118; fs:[0]` | **Confirmed** |
| Clear staging full tree at entry | `FUN_0052d8b0(0, -1)` after char resolve | **High** |
| Type gate `0x3a` | decomp `*(*(target+0xa8)+0x38) == 0x3a` | **Confirmed** (numeric) |
| Rolled vs type-0 reward split | `FUN_004d08c0` vs `FUN_004cf100` | **High** |
| Staging payload fields | `+0x20/+0x24` match; `+0x2c` ready; `+0x28` id | **High** |
| Sole caller | xref `0x009245e6` only | **Confirmed** |

---

## 4. Body CF (major stages ≡ raw)

| Stage | Match |
|---|---|
| Resolve target + char + early out | **Yes** |
| Staging clear | **Yes** |
| Type 0x3a branch with vectors `+0x1d8` / `+0x234` / `+0x244` | **Yes** |
| Active mission walk + turn-in ready | **Yes** |
| Offer collect + `FUN_004e54a0` | **Yes** |
| Cap >7 → toast abort | **Yes** |
| Reward loop `FUN_004d08c0` | **Yes** |
| Non-0x3a `FUN_004cf100` path | **Yes** |
| List teardown + SEH restore | **Yes** |

Decompiler `operator_delete` “does not return” on vector teardown is a **false noreturn** shape (shared with other MSVC vector cleanups); control rejoins epilogue (`ret 0xC`).

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Overall CF graph | **High** | Large but consistent with raw |
| ABI ret 0xC | **Confirmed** | |
| Mission staging integration | **High** | Dual callees sealed elsewhere |
| Type `0x3a` / `0x12` product English | **Open** | numeric only |
| param_3 meaning at sole site | **Medium** | formal used in 0x3a reward path |
| `unaff_EDI` to CheckMissionRequirements | **Open** | residual |
| Inferred function name | **Medium** | role sealed, product string absent |

---

## 6. Surviving contract

```
Mission_ProcessInteractOfferStaging(tfidBlock, &outId, rollOrCtx):
  target = resolve(tfidBlock[1].coid)
  char   = resolve(tfidBlock)->GetCharacterComponent()  // vtbl+0x210
  if !char: return
  ClearMissionStaging(char, 0, -1)
  if target && type==0x3a:
    maybe bind outId from linked objects
    stage matching actives (turn-in ready @ payload+0x2c)
    collect offerable missions → for each new: stamp staging; FillRolledRewards(def, char, rollOrCtx)
  else:
    if hash char[0x152] hit: FillType0Rewards(...); set outId; patch ready
// ret 0xC
```

---

## 7. Gaps / open

1. Product / packet name of caller `0x009245e6`.
2. English for type ids `0x3a`, `0x12`.
3. `unaff_EDI` third arg residual on requirements checks.
4. Whether `param_3` is always nonzero (RNG) at live site — needs caller dual.
5. Runtime / bit-exact open.
6. Full MSVC vector exception paths not line-audited beyond epilogue seal.

**Verdict:** **accept-with-gaps**.
