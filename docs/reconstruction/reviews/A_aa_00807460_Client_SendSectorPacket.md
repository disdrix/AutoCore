# Review A (reconstruction fidelity): `aa_00807460` Client_SendSectorPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00807460` |
| **VA** | `0x00807460` |
| **Canonical name** | `Client_SendSectorPacket` |
| **System** | network-sector (transport used by interact + skill C2S) |
| **Review date** | `2026-07-29` (strengthen pass — interact/skill + expanded census) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00807460_Client_SendSectorPacket.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00807460_Client_SendSectorPacket.md` |
| Raw | `docs/reconstruction/raw/aa_00807460_Client_SendSectorPacket.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendSectorPacket.cpp` |
| Residual scratch | `docs/reconstruction/reviews/a_00807460.md` |
| TNL enum | `lib/TNL.NET/TNL.NET/Entities/RPCEvent.cs` (`RPCGuaranteeType`) |
| Live Ghidra | decompile `0x00807460` + `read_memory` 48B + assembly context on ≥40 call sites (incl. skill/interact) |

---

## 2. Purpose (from unit)

Generic C2S sector transport: if `client+0xc78` (sector connection) non-null, call `conn->vtbl+0x18(-1, buffer, (int)size, reliabilityFlags)`. Always returns 0. Shared by **interact** (`Client_InteractClickPickTarget` class-4 send) and **skill** (`Client_RequestCastSkill` 0x2030/0x28) among ~67 C2S builders.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Connection object at client+0xc78 | **High** | asm `CMP [ECX+0xC78],0` |
| Send vtable slot +0x18 | **High** | `CALL [EDX+0x18]` |
| size is signed short promoted (MOVSX) | **High** | `MOVSX EAX, word [ESP+…]` |
| First send arg is always `-1` / `0xFFFFFFFF` | **High** | `PUSH -1` |
| Reliability flags = `~(EAX>>2)&2` ∈ {0,2} | **High** | SHR/NOT/AND sequence; live bytes match |
| TNL map: 0=Ordered, 1=Guaranteed, 2=Unguaranteed | **High** | `RPCEvent.cs` |
| Skill `RequestCastSkill` sets `EAX=8` → flags 0 | **High** | asm @ `0x00941883` |
| Interact `InteractClickPickTarget` sets `EAX=8` → flags 0 | **High** | asm @ `0x00924fc0` |
| Large call-site census → flags 0 (Ordered) | **High** | ≥40 sites; idioms: lit 8 / EBP under CMP==8 / CMP EAX,8 |
| Null conn → silent skip + return 0 | **High** | intentional |
| Always returns 0 | **High** | `XOR EAX,EAX; RET 8` |
| Control flow preserved clean ≡ raw ≡ live | **High** | scaffold rewrite |
| Every one of 67 xrefs forces bit3 | **Probable** | rare UI site `0x0086d0d1` (0x20c6) lacks local lit 8 |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| if this+0xc78 != 0: (*conn)->vt+0x18(0xffffffff, buffer, (int)size, ~(EAX>>2)&2) | **Yes** (clean ≡ raw ≡ live asm + bytes) |
| return 0 | **Yes** |
| Skill path: pack 0x2030 + size 0x28 + EAX=8 | **Yes** (`0x00941883`) |
| Interact path: size 0x10 + EAX=8 + this=`DAT_00d1a840` | **Yes** (`0x00924fc0`) |

---

## 5. Gaps (remaining)

1. Original symbol of connection vtbl+0x18 method (PDB unknown)
2. Whether `client+0xc78` is always identical to `DAT_00d1b4b8` / `g_pSectorNetConnection_INFERRED` (sibling dual-path residual)
3. Exhaustive 67-xref proof that every site forces EAX bit3 (skill/interact sealed; rare UI open)
4. Runtime / bit-exact / image diff (policy)

**Verdict:** **accept-with-gaps** — dual residual **flag formula + EAX=8 contract (skill/interact + census)** and **null-conn silent drop** sealed; only verification/runtime, connection-identity, and rare non-skill UI EAX provenance remain.
