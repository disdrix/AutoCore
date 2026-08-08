# Review A (reconstruction fidelity): `aa_00930360` Client_SortTargetListByViewAngle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930360` |
| **VA** | `0x00930360`–`0x00930691` inclusive (**0x332** B / 818 B) |
| **Canonical name** | `Client_SortTargetListByViewAngle_Inferred` |
| **Ghidra name** | `FUN_00930360` |
| **Review date** | `2026-08-05` (MEGA-023 OWN-ONLY dual seal) |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00930360_Client_SortTargetListByViewAngle_Inferred.md` |
| **System** | skills-abilities / client target selection |
| **Evidence pass** | Live `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` |
| **Verdict** | **accept-with-gaps** under `_Inferred` product plate |

**Tools:** decompile + disassemble_function + read_memory. **No** `disassemble_bytes`. **No** Launcher.

---

## 1. Purpose

**In-place reorder** of a `TFID_16` target list by a **view-angle score** built from the local player's forward/right basis and each resolved object's world position. Sole caller: dualed `Client_CycleHostileTarget_Inferred` (`0x00943340`) immediately after `Skill_GatherTargetsInArea`.

Not distance-only sort. Not selection apply (that is `FUN_0093e120`). Not gather.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-023 append) | `docs/reconstruction/raw/aa_00930360_FUN_00930360.md` |
| Annotated | `docs/reconstruction/raw/aa_00930360_FUN_00930360.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Client_SortTargetListByViewAngle_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00930360.cpp` |
| Retired scaffold | `Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00930360.cpp` |
| Function records | `aa_00930360_FUN_00930360.md`, named record |
| Live decompile | ≡ raw CF spine (2026-08-05 ≡ 2026-07-23) |
| Live asm | full `disassemble_function`; tail `C2 0C 00` |
| Constants | `read_memory` `a0f2a0`/`a0f518`/`a10e74`/`aaa668` |
| Comparator | `read_memory` @ `0x0092cdd0` |
| Caller | `0x00943440` assembly_context |

---

## 3. Signature (sealed)

```c
// stdcall RET 0xC; void — NOT thiscall
void Client_SortTargetListByViewAngle_Inferred(
    void *client,           // [EBP+8]
    TFID_16 *tfidList,      // [EBP+0xC] in/out
    unsigned *countInOut);  // [EBP+0x10]
```

| Item | Evidence | Conf |
|---|---|---|
| 3 stack args | entry `MOV EBX,[EBP+8]`; count `[EBP+10]`; list `[EBP+0xC]` | **High** |
| `RET 0xC` | tail `C2 0C 00` @ `0x0093068f` | **High** |
| void | no EAX product store; count out-param | **High** |
| not ECX this | client from stack; caller pushes client last | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| SEH prolog `LAB_009ac665` | **Yes** | **High** |
| player `@client+0xe98` vtbl `+0x1a0` pos / `+0x1a4` quat | **Yes** | **High** |
| `FUN_004e8a40` forward + `FUN_004e8ad0` right | **Yes** | **High** |
| empty vector triad; loop `*count` | **Yes** | **High** |
| resolve `004bb950`; skip null | **Yes** | **High** |
| virtual `+0x144`; delta from `obj+0x80/84/88` | **Yes** | **High** |
| distSq / sqrt; score half-plane formula | **Yes** | **High** |
| InsertN `00408640` / construct `00409e20`; stride `>>4` | **Yes** | **High** |
| sort `00409bd0` + cmp `LAB_0092cdd0` score@+4 ascending | **Yes** | **High** |
| rewrite TFID from `obj+0x160` (16 B); `*count = n` | **Yes** | **High** |
| `operator_delete` then SEH + RET (not noreturn) | **Yes** (asm) | **High** |
| Live decompile ≡ raw body | **Yes** | **High** |

### Score formula (bytes)

```
if dist <= 0:  score = 2.0f
else:
  u = delta / dist
  fDot = forward · u
  rDot = right · u
  if rDot <= 0: score = fDot + 1.0f
  else:         score = fDot * (-1.0f) - 1.0f
```

Constants sealed: `1.0f`, `0.0f`, `2.0f`, `−1.0f` via `read_memory`.

### Comparator `LAB_0092cdd0`

```
bool cmp(L, R) { return R.score > L.score; }  // ascending by float@+4
```

Bytes: `8B442408 8B4C2404 F30F104004 0F2F4104 7603 B001 C3 32C0 C3`.

---

## 5. Call surface

| Dir | Target | Notes |
|---|---|---|
| Sole caller | `Client_CycleHostileTarget_Inferred` @ `0x00943440` | 1 UNCONDITIONAL_CALL |
| Callees | vtbl+0x1a0/1a4, `004e8a40`, `004e8ad0`, `004bb950`, virt+0x144, `00408640`, `00409e20`, `00409bd0`, `LAB_0092cdd0`, `operator_delete` | listed in analyze_complete |

---

## 6. Confidence

| Claim | Level |
|---|---|
| ABI RET 0xC / 3 stack args / void | **High** |
| CF spine + score formula + constants | **High** |
| Sort key float@+4 ascending | **High** |
| Role: view-angle reorder of TFID list | **High** |
| Product C++ / PDB method name | **Inferred** |
| Virtual `+0x144` English | **Open** |
| client `+0xd34` ECX preload English | **Open** |
| Elem0x10 4th dword always distSq | **Probable** |
| Runtime / bit-exact / differential | **Open** |

---

## 7. Gaps

1. Product demangled name (keep `_Inferred`).
2. Virtual `+0x144` and `client+0xd34` product English.
3. Whether cycle UX intends ascending (right-forward first) as design or accident — sealed as bytes only.
4. Nested dual residual on `FUN_00409e20` / `FUN_00409bd0` / comparator leaf as standalone units.
5. Runtime Confirmed / bit-exact / image diff.

---

## 8. Verdict

**accept-with-gaps** — ABI, CF, score geometry, sort key, sole caller, and rewrite path sealed from live image; product plate remains `_Inferred`; no runtime Confirmed.
