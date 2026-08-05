# Review B (skeptical / adversarial): `aa_006374f0` TNL_GroupReactionCall_UnpackData

| Field | Value |
|---|---|
| **Stable ID** | `aa_006374f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_006374f0_TNL_GroupReactionCall_UnpackData.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `__thiscall` single-arg helper | Epilogue **`RET`/`add esp,0x2940`**; two stack params | **Falsified** — **cdecl two-arg** |
| 2 | Generic ByteBuffer unpack for any opcode | Caller only when `0x206c`; tag store `0x206c`; siblings separate | **Falsified generic** — **opcode-specific** |
| 3 | Same wire as `Client_RecvGroupReactionCall` apply path | Apply path is `0x008092a0` on normal dispatch; this is special-message rebuild | **Distinct units** — do not merge blindly |
| 4 | Entry stride 0x18 (like MapInstanceList) | Loop `+0x28`; size `*0x28+1` | **Falsified** — **0x28** |
| 5 | Count is u32 on wire | First read **8 bits** | **Falsified** — **u8** |
| 6 | type==1 second field is integer only | Bytes **`movss`** store to entry+4 | **Falsified int-only** — **float bits** |
| 7 | Flags via `BitStream_readFlag` call | No such callee; inlined bit tests | **Confirmed inlined** |
| 8 | size field must equal full logical header+entries | Retail formula `count*0x28+1` | **Sealed retail** — meaning **open** |
| 9 | Runtime verified | No live capture | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl + out**/in* + RET | **High** | Stack smash |
| Opcode `0x206C` sole caller | **High** | Mis-route special messages |
| Wire type branch + stride 0x28 | **High** | Corrupt reaction batch |
| ByteBuffer vtbl/size/owns/refcount | **High** | Leaks / double-free |
| Float on type==1 | **High** | Wrong variable payload |
| Field English / map semantics | **Low–Medium** | Wrong server pack labels |
| size `+1` semantics | **Medium** | Over/under-copy ports |
| Clean flag helpers vs raw bits | **Medium** | Use raw for bit-exact |

---

## 3. Cross-check against raw + bytes

```
raw:
  local_27ec = 0x206c
  FUN_0042b3a0(param_2[3], param_2[4])
  readBits(8) count; loop type; type==1 u16+u32; else readInt(19)+u64+flags
  size = count*0x28+1; new(0x18) ByteBuffer; vtbl 009d7b00; malloc; owns=1
  memcpy; *out=bb; ref++; release in

bytes:
  entry SEH + chkstk 0x2934
  C7 … 6C200000 tag
  mid: movss [esi+4] on type-1 path
  epilogue: add esp,0x2940; C3
```

≡ same CF. No inventory / mission-dialog body logic inside this unit (dialog soft-pedal is consumer-side commentary elsewhere).

---

## 4. Surviving contract for AutoCore

```csharp
// S2C GroupReactionCall (0x206C) special-message unpack (client).
// Wire on BitStream:
//   byte count;
//   repeat count:
//     byte type;
//     if type == 1: u16; f32bits
//     else: u19; u64; flag; flag
// Rebuild ByteBuffer:
//   data size = count * 0x28 + 1
//   vtbl shared with other TNL ByteBuffer unpackers (009d7b00)
```

- Server pack mirror should match **bit** layout, not necessarily the odd `+1` size field semantics without capture.
- Do not assume this blob is identical to the apply-path packet consumed by `Client_RecvGroupReactionCall`.

---

## 5. Residual risks

1. Stack image field offsets for type-1 vs else need a dedicated layout diagram against a live pack.
2. Null `operator_new` path may null-deref on memcpy — retail behavior, not a port “fix” without evidence.
3. Name `TNL_GroupReactionCall_UnpackData` is role-sealed **INFERRED** (opcode + dispatch docs), not RTTI.

**Verdict:** **accept-with-gaps** — adversarial pass keeps CF seal; product field names open.
