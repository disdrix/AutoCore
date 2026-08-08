# Review B (skeptical / adversarial): `aa_0040aff0` Object_CopyTfid16At228_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040aff0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0040aff0_Object_CopyTfid16At228_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/offset; product name residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function returns a **pointer into** the object (like GetWorldPositionPtr) | Bytes: dest is stack arg; four stores to `*out` | **Falsified** — out-copy |
| 2 | Source is float3 position @ +0x228 | Width 16 B; callers use TFID equals/not-equals | **Falsified as position** |
| 3 | `cdecl` / no stack cleanup | `ret 4` | **Falsified** — thiscall + 1 arg |
| 4 | Mutates object TFID | Only loads from this | **Falsified** |
| 5 | Unique to AI FindTarget | 20+ call sites across skill/filter/net | **Falsified as AI-only** |
| 6 | Decompiler `void` means EAX unused | EAX = out at entry and preserved | **Survives as return=out** |
| 7 | Offset is +0x214 (mode-table residual wording) | Bytes `0x228`; mode-4 residual is dual +0x214 fields on **other** objects | **Offset sealed 0x228** |
| 8 | Scaffold name CalleeOf_FindTarget is product | Generic leaf | **Superseded** by role name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x228 / 16 B / ret 4 | **High** | Wrong identity layout |
| TFID role | **High** | Confuse with pos/map |
| Product symbol | **Open** | Doc only |
| Runtime | **Open** | Unverified live |

---

## 3. Cross-check raw + live bytes

```
0040aff0  mov  eax, [esp+4]           ; out
0040aff4  add  ecx, 0x228
0040affa  push esi
0040affb  mov  esi, [ecx]
0040affd  mov  edx, eax
0040afff  mov  [edx], esi
… three more dword pairs …
0040b011  pop  esi
0040b012  ret  4
```

Live 2026-08-04 ≡ 2026-07-23 raw decompile.

---

## 4. Surviving contract for AutoCore

```
out = Object_CopyTfid16At228(objectWithTfidAt228);
// out is 16 B; compare via TFID_EqualsObjectId / TFID_NotEquals
```

Do not invent server-side mutation; leaf copy only.

**Verdict:** **accept**.
