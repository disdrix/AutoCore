# Review A (reconstruction fidelity): `aa_0067b0e0` netAddress_CopyAssign

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067b0e0` |
| **VA** | `0x0067b0e0` |
| **Body span** | `0067b0e0`–`0067b102` exclusive (34 B) |
| **Canonical name** | `FUN_0067b0e0` |
| **Proposed name** | `netAddress_CopyAssign` / `Address_CopyFrom` |
| **System** | `network-nazgul-netAddress` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W25-P) |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_0067b0e0_netAddress_CopyAssign.md` |
| **Dual status** | **Present (first dual seal)** |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + xrefs |
| **Verdict** | **accept-with-gaps** — CF/ABI sealed; product English open |

---

## 1. Purpose

**POD copy-assign** for the nazgul **16-byte Address** type:

1. `this` (ECX) = destination
2. Stack arg = source pointer
3. Copy four consecutive dwords (`+0`, `+4`, `+8`, `+0xC`)
4. `ret 4`

No null checks, no self-assign early-out, no heap, no callees.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0067b0e0_FUN_0067b0e0.md` (+ v2026-07-29) |
| Annotated | `docs/reconstruction/raw/aa_0067b0e0_FUN_0067b0e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/netAddress_CopyAssign.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0067b0e0.cpp` |
| Function records | `functions/aa_0067b0e0_FUN_0067b0e0.md`, `functions/aa_0067b0e0_netAddress_CopyAssign.md` |
| Live decompile | Ghidra `FUN_0067b0e0` — 4 dword stores |
| Sibling context | `A_aa_0067b110_netAddress_TrivialDtor`, `A_aa_0067ba30_netSocket_GetPeerAddress` |

---

## 3. Seal: body bytes + CF (High)

Body range: **`0067b0e0`–`0067b102`**.

`read_memory` @ `0x0067b0e0`:

```
8B C1                 mov eax, ecx          ; dest this
8B 4C 24 04           mov ecx, [esp+4]      ; src
56                    push esi
8B 31                 mov esi, [ecx]
8B D0                 mov edx, eax
89 32                 mov [edx], esi        ; +0
8B 71 04 / 89 72 04                         ; +4
8B 71 08 / 89 72 08                         ; +8
8B 49 0C / 89 4A 0C                         ; +0xC
5E                    pop esi
C2 04 00              ret 4
```

Hex (executed body):

```
8bc18b4c2404568b318bd089328b71048972048b71088972088b490c894a0c5ec20400
```

| Claim | Evidence | Conf |
|---|---|---|
| 4 dword stores only | decompile + bytes | **Confirmed** |
| thiscall dest + 1 stack src | `8B C1` + `[esp+4]` + `ret 4` | **Confirmed** |
| 16-byte Address POD | cluster + GetPeer `namelen=0x10` | **High** |
| No callees / branches | bytes continuous store seq | **Confirmed** |
| Clean ≡ raw ≡ live | three-rep | **High** |
| Product class spelling | no plate string on VA | **Open** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name role = Address copy | **High** | callers + sibling duals |
| Product/PDB identifier | **Open** | `netAddress` vs `Address` |
| Field layout English | **Medium** | sockaddr_in overlay likely; not byte-sealed here |
| Port as memcpy(16) | **High** | equivalent for non-overlap |

---

## 5. Callers (xrefs)

| Site | Function |
|---|---|
| `0x0067ba8a` | `FUN_0067ba30` GetPeerAddress |
| `0x0067b9fa` | `FUN_0067b9a0` GetSockName twin |
| `0x0067159d` | `FUN_00671570` |
| `0x0067c0e4` | `FUN_0067c060` |
| `0x0067c1a4` | `FUN_0067c120` |

---

## 6. Gaps

1. Product class spelling.
2. Exact sockaddr field names / endian of port word.
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps** — dual complete for OWN VA; CF and ABI sealed.
