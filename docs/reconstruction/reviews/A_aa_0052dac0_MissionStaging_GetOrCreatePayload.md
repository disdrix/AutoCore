# Review A (reconstruction fidelity): `aa_0052dac0` MissionStaging_GetOrCreatePayload

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052dac0` |
| **VA** | `0x0052dac0` |
| **Canonical name** | `MissionStaging_GetOrCreatePayload` (role-sealed; product English open) |
| **Ghidra name** | `FUN_0052dac0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live asm) |
| **Counterpart** | `reviews/B_aa_0052dac0_MissionStaging_GetOrCreatePayload.md` |
| **System** | `missions-progression` |
| **Parent chain** | Nested via staging map helpers shared with GiveMission (`FUN_00538a40` / `FUN_0052c700` / `FUN_0052d8b0`) |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Character **mission staging map get-or-create**:

1. `this` (ECX) = character (container with map @ `+0x508`, end @ `+0x50c`).
2. Lower-bound key = stack mission id via `FUN_00538a40` with map `this = char+0x508`.
3. **Hit** (node ≠ end sentinel): return **`node + 0x18`** (12-dword staging payload base).
4. **Miss + create flag == 0**: return **`NULL`**.
5. **Miss + create flag ≠ 0**: fill 11× `0xFFFFFFFF` dwords + trailing byte `0`, call `FUN_0052c700(this, key, payload*)`, return payload base (`node+0x18`).

Does **not** interpret reward/offer COIDs; only returns the staging region pointer. Nested residual of GiveMission staging tree (`+0x508`) family — not a direct CALL from `0x005327c0` body, but shares map helpers used on grant notify / dialog paths.

**ABI (asm-sealed):**

```c
void* __thiscall MissionStaging_GetOrCreatePayload(
    Character* this /*ECX*/,
    uint32_t key /*stack0*/,
    char createIfMissing /*stack1*/);
/* ret 8 */
```

| Slot | Role | Evidence |
|------|------|----------|
| ECX | character | `MOV ESI,ECX`; `LEA ECX,[ESI+0x508]` |
| stack0 | mission key | `LEA EAX,[ESP+0x3c]` → key* into lower_bound |
| stack1 | create flag | `CMP byte [ESP+0x40],0` |
| EAX | payload* or 0 | hit `ADD EAX,0x18`; miss `XOR EAX,EAX` |
| epilogue | **`RET 8`** | three exits `C2 08 00` |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052dac0_FUN_0052dac0.md` |
| Annotated | `docs/reconstruction/raw/aa_0052dac0_FUN_0052dac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0052dac0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052dac0_FUN_0052dac0.md` |
| Live decompile | Ghidra `batch_decompile` `0x0052dac0` — CF ≡ raw |
| Live bytes | `read_memory` 160 B @ entry — map `+0x508`/`+0x50c`, triple `ret 8` |
| Store twin dual | `A/B_aa_0052c700_MissionStagingStore` |
| Lower-bound dual | `A/B_aa_00538a40_*` |
| Callers | 5 CODE xrefs: dialog UI + reward fill paths |

**Not performed:** `disassemble_bytes`, Launcher, live staging capture.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Boundary @ `0x0052dac0` | **High** | Named capture + xrefs |
| Map base `char+0x508` / end `+0x50c` | **High** | Asm `LEA ECX,[ESI+0x508]`; `CMP [ESI+0x50c]` — decompiler flattens map-this |
| Hit → `node+0x18` | **High** | `ADD EAX,0x18` |
| Miss + flag0 → 0 | **High** | `XOR EAX,EAX` |
| Miss + flag1 → `FUN_0052c700` insert | **High** | Call + return EAX from store |
| Default payload = 11× `0xFF…` + byte 0 | **High** | Create path stores |
| `__thiscall` + **`RET 8`** | **High** | Three epilogues |
| Product name | **Open** | Role sealed |
| “Reward region” English | **Tentative** | Layout is staging 0x30 blob; dialog consumers treat as offer/reward chrome |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| lower_bound map@+0x508 | Yes (asm corrects decompiler this) |
| hit → node+0x18 | Yes |
| miss flag0 → 0 | Yes |
| miss flag1 → fill + store | Yes |
| No invent side effects beyond store callee | Yes |

### Callers (sealed set)

| Site | Function | create |
|---|---|---|
| `0x00943a85` | `Client_ShowNpcMissionDialogUI` | **0** (lookup only) |
| `0x004d0912` | `FUN_004d08c0` | **1** |
| `0x004d5d20` / `0x004d5e90` / `0x004d63f6` | `FUN_004d5c10` | **1** |

---

## 5. Gaps

1. Product/PDB symbol.
2. Full English for payload slots (see `FUN_0052c700` dual — NPC/AutoAssign sealed on award path).
3. Runtime dialog grant matrix not observed.

**Verdict:** CF/ABI/map layout **High**. **accept-with-gaps.**
