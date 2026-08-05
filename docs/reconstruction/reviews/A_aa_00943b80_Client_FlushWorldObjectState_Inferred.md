# Review A (reconstruction fidelity): `aa_00943b80` Client_FlushWorldObjectState_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00943b80` |
| **VA** | `0x00943b80`–`0x00943dae` |
| **Canonical name** | `Client_FlushWorldObjectState_Inferred` (**Probable**) |
| **Prior scaffold** | `FUN_00943b80` / `Named_CalleeOf_Named_Server_needs_an_update_00943b80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W23-E |
| **Counterpart** | `reviews/B_aa_00943b80_Client_FlushWorldObjectState_Inferred.md` |
| **System** | client-session / world-object containers |
| **Verdict** | **accept-with-gaps** — ABI + stage CF sealed; nested product names + free-loop open |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ bounds/callers/callees/xrefs). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

**Flush client world-object / related containers** when leaving gameplay or re-initing sector networking:

| Caller | Context | flag |
|---|---|---|
| `Client_TeardownGameplaySession` (`00944b20`) | full session teardown | **0** |
| `Net_InitNetworking_sector` (`009493c0`) | sector reconnect bring-up | **0** |
| `FUN_00943fb0` / `FUN_009492d0` / `FUN_008153b0` | leave / reinit family | **0** |
| `FUN_009466f0` | hard path (push 1) | **1** |

Stages (live ≡ raw): host flag clear → equip-gfx optional clear → helpers → optional UI vtbl → drain `+0xd28` → re-ring / free → two-pass TFID export → finish helpers → optional UI vtbl `+0x2a4`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00943b80_FUN_00943b80.md` (+ W23-E live seal) |
| Annotated | `docs/reconstruction/raw/aa_00943b80_FUN_00943b80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_FlushWorldObjectState_Inferred.cpp` |
| Alias | `docs/reconstruction/reconstructed-exact/FUN_00943b80.cpp` |
| Function record | `docs/reconstruction/functions/aa_00943b80_Client_FlushWorldObjectState_Inferred.md` |
| Live decompile | Ghidra `0x00943b80` — **≡** raw |
| Entry bytes | `8b 87 04 0e 00 00` → `[edi+0xe04]` |
| Exit bytes | `83 c4 08 c2 04 00` → `add esp,8; ret 4` |
| Call sites | push 0 + `mov edi,esi` at teardown/net; push 1 at `00946972` |
| Related duals | EquipGfxHost clear; ObjectList_ExportTfidsToMap; TeardownGameplaySession |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| `this` | **EDI** (entry `[edi+…]`; sites `mov edi,esi`) |
| flag | stack char; **`RET 4`** |
| Body | `00943b80`–`00943dae` |

```c
void Client_FlushWorldObjectState_Inferred(void *self /*EDI*/, char flag);
```

### 3.2 Always-on stages — **SEALED**

| Stage | Evidence |
|---|---|
| Zero `*(e04→e894)+0x8c` | first stores in decompile |
| Optional `FUN_004962b0` if e04/e898 | branch + callee list |
| `FUN_0093e120(0)`, `FUN_00997120` | callees |
| Double `FUN_00415e90` | two calls |
| `FUN_009306d0`, `FUN_008026a0` | callees |
| Zero `client+0xe08` | store |
| Drain `+0xd28` with vtbl+4(1) | loop body |
| 2× `FUN_004bae00` + `FUN_00933370` | loop i=2 |
| `FUN_004bbeb0`, `FUN_0092f3b0` | callees |

### 3.3 flag-dependent — **SEALED**

| flag | Behavior |
|---|---|
| `!=0` | vtbl `+0x2a8` + `FUN_0051f400`; insert at `+0xf00`; exit vtbl `+0x2a4` |
| `==0` | if `+0xf38` non-null, zero `*(+0xf38)+0xc70` |

### 3.4 Three-rep — **SEALED**

live decompile ≡ raw body ≡ annotated stages ≡ clean plate order.

---

## 4. Gaps (owned)

| Gap | Severity | Notes |
|---|---|---|
| Product English name | Med | `_Inferred`; role High from callers |
| Exact type of `+0xd28` container | Med | list-like walk + isnil@+0x29 |
| Free-loop when isnil==0 | Med | decompiler noreturn on `operator_delete` |
| Nested helper product names | Med | not owned |
| Runtime | Open | deferred |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| EDI this + stack flag + RET 4 | **High** |
| Stage order / always vs flag | **High** |
| Role = world/container flush on leave | **High** |
| Name `Client_FlushWorldObjectState` | **Probable** |
| Nested semantics | **Tentative** |

**Verdict:** **accept-with-gaps**.
