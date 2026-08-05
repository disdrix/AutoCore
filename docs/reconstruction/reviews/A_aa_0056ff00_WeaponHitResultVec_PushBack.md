# Review A (reconstruction fidelity): `aa_0056ff00` WeaponHitResultVec_PushBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056ff00` |
| **VA** | `0x0056ff00` |
| **Body** | `0x0056ff00`–`0x0056ff60` (97 bytes) |
| **Canonical name** | `WeaponHitResultVec_PushBack` (Ghidra `FUN_0056ff00`; **Inferred**) |
| **Review date** | `2026-07-29` (W24-R dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0056ff00_WeaponHitResultVec_PushBack.md` |
| **System** | combat / weapon multi-hit staging |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Purpose

Append one **0x20-byte** POD hit-result record to a vector shell used by `Weapon_ApplyDamageToTargets_Inferred`. Classic MSVC push_back: in-place construct when room, else grow via sibling insert helper.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0056ff00_FUN_0056ff00.md` (+ W24-R live append) |
| Annotated | `docs/reconstruction/raw/aa_0056ff00_FUN_0056ff00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WeaponHitResultVec_PushBack.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0056ff00.cpp` |
| Function record | `docs/reconstruction/functions/aa_0056ff00_FUN_0056ff00.md` |
| Live decompile | `decompile_function` @ `0x0056ff00` ≡ raw |
| Machine | `read_memory` 96 B+ @ `0x0056ff00` |
| Callers | `get_function_callers` / analyze → `FUN_0056e000` only |
| Parent dual | `A_aa_0056e000_Weapon_ApplyDamageToTargets_Inferred` |

---

## 3. Byte seal (`read_memory` @ `0x0056ff00`)

```
56              push esi
8B F1           mov  esi, ecx            ; vec
8B 56 04        mov  edx, [esi+4]        ; begin
...
C1 F9 05        sar  ecx, 5              ; size = (end-begin)/0x20
...
C1 F8 05        sar  eax, 5              ; capacity
...
E8 ..           call FUN_0056f1e0
83 C4 14        add  esp, 0x14           ; cdecl cleanup
83 C7 20        add  edi, 0x20           ; end += stride
...
C2 04 00        ret  4                   ; both epilogues
```

Full hex (97 B):
```
568bf18b560485d2750433c9eb088b4e082bcac1f90585d274318b460c2bc2c1f8053bc873258b4424088b4c2408578b7e085056516a0157e8a3f2ffff83c41483c720897e085f5ec204008b5424088b4608526a01508bcee853fbffff5ec20400
```

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall` vec + stack value* | **High** | ECX→ESI; `[esp+8]` after push; `ret 4` |
| Stride **0x20** | **High** | `sar 5`; `add edi,0x20` |
| Shell +4/+8/+0xc | **High** | `mov edx,[esi+4]`; end/cap loads |
| Fast = POD copy 8 dwords | **High** | callee `FUN_0056f1e0` copies 8×DWORD |
| Slow = grow helper | **High** | `call FUN_0056fab0` with ECX=vec |
| Sole caller weapon path | **High** | analyze callers = `FUN_0056e000` |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| begin==0 → grow | **Yes** |
| size < cap → fill + bump | **Yes** |
| else grow | **Yes** |
| No invented insert-at-middle | **Yes** |
| `ret 4` | **Yes** |

---

## 5. Caller usage (context only)

`Weapon_ApplyDamageToTargets_Inferred` stages a local `Elem20` (entity `+0x160` guid dwords + score/flags) and pushes twice (miss-flag path + hit path). Downstream flush uses `>>5` count into `Client_Combat_ApplyMultiTargetHits`.

---

## 6. Gaps

1. Product/PDB name for vector/element type — open (Inferred).
2. Full 0x20 record field English — residual at caller.
3. Nested duals for `FUN_0056f1e0` / `FUN_0056fab0` — scaffold only.
4. Runtime / bit-exact — open.

**Verdict:** **accept-with-gaps**
