# Review A (reconstruction fidelity): `aa_005405e0` Client_IsRequirementEventActive

| Field | Value |
|---|---|
| **Stable ID** | `aa_005405e0` |
| **VA** | `0x005405e0` |
| **Canonical name** | `Client_IsRequirementEventActive` (proposed / role-sealed) |
| **Prior names** | `FUN_005405e0`; scaffold alias `Named_CalleeOf_CVOGCharacter_CheckMissionRequirements_005405e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live asm seals) |
| **Counterpart** | `reviews/B_aa_005405e0_Client_IsRequirementEventActive.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** (product English open; CF/ABI/vector sealed) |
| **Scratch** | `tmp/a_005405e0.md` |

---

## 1. Purpose

**Global active-event membership test** for mission `RequirementEventId`:

1. Linear scan dword vector **`[DAT_00b04718, DAT_00b0471c)`**.
2. If any element equals stack `eventId` → return **`1`** (AL).
3. If cursor reaches end → return **`0`**.

Used solely by `CVOGCharacter_CheckMissionRequirements` when mission def **`+0x118` ≠ -1** (`RequirementEventId` from WAD / `Mission.Read`).

**Calling convention (asm-sealed):**

| Slot | Role | Evidence |
|------|------|----------|
| *(no this)* | free function | no ECX setup in body; call site `PUSH id; CALL; ADD ESP,4` |
| stack0 | **event id** (`int`) | `MOV EDX,[ESP+4]` |
| return | **bool** in **AL** (`0` / `1`) | `XOR AL,AL` / `MOV AL,1` |
| epilogue | bare **`RET`** (cdecl) | `C3` both exits |

```c
bool /* AL */ __cdecl Client_IsRequirementEventActive(int requirementEventId);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005405e0_FUN_005405e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005405e0_FUN_005405e0.annotated.md` |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/FUN_005405e0.cpp` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGCharacter_CheckMissionRequirements_005405e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005405e0_FUN_005405e0.md` |
| Parent dual | `A/B_aa_005462b0_*` + residual `reviews/a_005462b0.md` |
| Live decompile | Ghidra `batch_decompile` `0x005405e0` (2026-07-29) — **CF ≡ raw** |
| Live asm | `get_assembly_context` body + Requirements site `0x00546394` |
| Live bytes | `read_memory` `0x005405e0` length 40 |
| Xrefs | `get_function_xrefs` — **sole** caller `CheckMissionRequirements` @ `0x00546394` |

**Not performed:** `disassemble_bytes` bulk, Launcher, live event-table capture, writers of `DAT_00b04718/1c`.

---

## 3. Body (authoritative asm / decompile)

### 3.1 Assembly (sealed)

```text
005405e0  MOV  EAX, [DAT_00b04718]   ; begin
005405e5  MOV  ECX, [DAT_00b0471c]   ; end
005405eb  CMP  EAX, ECX
005405ed  JZ   not_found             ; empty range
005405ef  MOV  EDX, [ESP+0x4]        ; eventId
loop:
005405f3  CMP  [EAX], EDX
005405f5  JZ   found
005405f7  ADD  EAX, 4
005405fa  CMP  EAX, ECX
005405fc  JNZ  loop
not_found:
005405fe  XOR  AL, AL                ; 0
00540600  RET
found:
00540601  MOV  AL, 1
00540603  RET
```

### 3.2 Decompile (raw ≡ live)

```c
uint FUN_005405e0(int param_1)
{
  int *piVar1 = DAT_00b04718;
  while (true) {
    if (piVar1 == DAT_00b0471c) {
      return (uint)piVar1 & 0xffffff00; // decompiler noise for AL=0
    }
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 1;
  }
  return CONCAT31((int3)((uint)piVar1 >> 8), 1); // AL=1
}
```

**Prefer assembly:** returns are clean **`AL=0` / `AL=1`**, not meaningful upper EAX bits. `CONCAT31` / mask form is decompiler artifact.

### 3.3 Live bytes

```text
a1 18 47 b0 00  8b 0d 1c 47 b0 00  3b c1  74 0f
8b 54 24 04  39 10  74 0a  83 c0 04  3b c1  75 f5
32 c0  c3  b0 01  c3  cc cc cc cc
```

| Address | Role |
|---|---|
| `DAT_00b04718` | vector begin (`int*`) |
| `DAT_00b0471c` | vector end (`int*`, exclusive) |
| element stride | **4** (`ADD EAX,4`) |

---

## 4. Mission-path call site (sole xref)

```text
00546388  MOV  EAX, [ESI+0x118]     ; RequirementEventId
0054638e  CMP  EAX, -1
00546391  JZ   skip_event           ; -1 = unrestricted
00546393  PUSH EAX
00546394  CALL 0x005405e0
00546399  ADD  ESP, 0x4             ; cdecl cleanup
0054639c  TEST AL, AL
0054639e  JZ   hard_fail            ; not active → return -1
```

| Claim | Conf |
|---|---|
| Skip when `+0x118 == -1` | **High** |
| Fail when membership returns 0 | **High** (`TEST AL` / `JZ`) |
| **Sole** static caller | **High** (xref inventory) |
| `__cdecl` one arg | **High** (`ADD ESP,4`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function boundary `0x005405e0`–`0x00540603` | **High** | Bytes + pad `CC` |
| Linear scan `[begin,end)` for id | **High** | Body |
| Return bool AL 0/1 | **High** | Asm |
| cdecl stack arg | **High** | Call site cleanup |
| Sole caller = Requirements | **High** | xrefs |
| Arg = mission `RequirementEventId` (`+0x118`) | **High** | Parent dual + site |
| No side effects | **High** | Read globals only |
| Globals hold “active events” product set | **High** (role); **Open** who populates | Writers not dualed here |
| Product English name | **Tentative / Open** | Role sealed |
| Runtime event list contents | **Open** | Not captured |

---

## 6. Clean ≡ raw

| Stage | Match |
|---|---|
| Begin/end globals | **Yes** |
| Linear compare loop | **Yes** |
| Found → 1 / miss → 0 | **Yes** (asm clearer than CONCAT31) |
| Scaffold system `unknown` | **Gap** — dual sets `missions-progression` |

---

## 7. Open residuals

1. Product / RTTI name for this helper and the global vector.
2. Writers / packet path that fills `[DAT_00b04718, DAT_00b0471c)`.
3. Whether vector can hold duplicates (membership still correct either way).
4. Runtime / bit-exact.

---

## 8. Port contract (AutoCore)

```
// Client mission gate only:
bool IsRequirementEventActive(int eventId) {
  for (int* p = g_activeEventsBegin; p != g_activeEventsEnd; ++p)
    if (*p == eventId) return true;
  return false;
}

// Mission Requirements:
if (mission.RequirementEventId != -1) {
  if (!IsRequirementEventActive(mission.RequirementEventId))
    return hard_fail; // -1
}
// Server should own authority; this is client eligibility display/auto-grant filter.
```
