# Review A (reconstruction fidelity): `aa_0051f8e0` LookupRaceDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f8e0` |
| **VA** | `0x0051f8e0` |
| **Body span** | `0051f8e0` – `0051f90b` exclusive (**43** bytes / `0x2B`); pad `CC` |
| **Canonical name** | `FUN_0051f8e0` (Ghidra) |
| **Proposed name** | `LookupRaceDisplayName_Inferred` (**High** role) |
| **Rejected alias** | `Named_CalleeOf_Named_Combat_0051f8e0` — combat chain plate wrong; callers are UI requirements |
| **Review date** | `2026-08-05` (OWN-ONLY dual A/B **R12-017**) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ instructions) |
| **Counterpart** | `reviews/B_aa_0051f8e0_LookupRaceDisplayName_Inferred.md` |
| **System** | skills-abilities / client race display |
| **Parent (partition)** | `0x00846820` `UI_AppendCraftRequirements_Inferred` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Pure leaf helper that maps an integer **race id** to a **static product English** display name:

| raceId | String | VA |
|---:|---|---|
| 0 | `"Human"` | `0x00a40958` |
| 1 | `"Mutant"` | `0x00a40950` |
| 2 | `"Biomek"` | `0x00a40948` |
| else | `"Unknown"` | `0x00a37c4c` |

Used by item/craft UI requirement formatters for the race / **"Required Faction"** line after def vfunc `+0x14` returns a non-`-1` race id.

**ABI:** cdecl; raceId on stack; plain `ret`; returns `const char*` (rodata immediate).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12 re-verify) | `docs/reconstruction/raw/aa_0051f8e0_FUN_0051f8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051f8e0_FUN_0051f8e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0051f8e0.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/LookupRaceDisplayName_Inferred.cpp` |
| Function records | `docs/reconstruction/functions/aa_0051f8e0_FUN_0051f8e0.md`, `aa_0051f8e0_LookupRaceDisplayName_Inferred.md` |
| Peer class leaf | `LookupClassDisplayName_Inferred` `0x0051f940` (dualed) |
| Peer character wrapper | `Character_GetRaceDisplayName_Inferred` `0x00521800` (dualed; embeds same map) |
| Parent | `UI_AppendCraftRequirements_Inferred` `0x00846820` |
| Sibling short codes | `FUN_0051f910` HUM/MUT/BIO (context only) |

**This pass (live):** `decompile_function` @ `0x0051f8e0`; `analyze_function_complete` (name=`FUN_0051f8e0`); `disassemble_function`; `get_function_by_address`; `get_function_callers`; `get_xrefs_to`; `read_memory` entry/body + four product strings; caller decompiles of `0x00845360` / parent context. **Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledger edits, other VAs dualled.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 43 B / exclusive end `0051f90b` / pad CC / next `0051f910` | **High** | `get_function_by_address` + `read_memory` |
| cdecl 1-arg; `[esp+4]`; plain RET (`c3`) | **High** | entry + four exits |
| Leaf / no callees | **High** | analyze callees=[] |
| Race map 0/1/2/else + product strings | **High** | imm `mov eax` + `read_memory` ASCII |
| Static rodata return (not TLS ring) | **High** | no ring callees; callers use `007a6de0` |
| Callers: item + craft UI requirements | **High** | 2 UNCONDITIONAL_CALL xrefs |
| Parent uses as **"Required Faction"** name | **High** | parent raw + product string `0x00a6a1e0` |
| Role = race display name lookup | **High** | strings + peer class leaf + character wrapper map |
| Product/PDB method symbol | **Probable** | role High; symbol open → `_Inferred` |
| Runtime / bit-exact | **Open** | Terminal false |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ instructions

| Stage | Match |
|---|---|
| raceId==0 → Human | **Yes** |
| raceId==1 → Mutant | **Yes** |
| raceId==2 → Biomek | **Yes** |
| else → Unknown | **Yes** |
| Four plain RET exits / no side effects | **Yes** |

### 4.1 Machine cascade (sealed)

```text
mov eax, [esp+4]
sub eax, 0 / jz → Human
sub eax, 1 / jz → Mutant
sub eax, 1 / jz → Biomek
mov eax, &"Unknown" / ret
```

Identical sub/jz arm shape to dualed `Character_GetRaceDisplayName_Inferred` map arms; that wrapper adds ECX-this load of race `@+0x532` and TLS ring — **not** this leaf.

---

## 5. Gaps / open

1. Product/PDB method English (name is role-Inferred).
2. Short-code twin `0x0051f910` undualed (not OWN).
3. Runtime golden matrix / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF, ABI, strings, callers sealed; residual is product symbol English only.
