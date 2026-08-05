"""
Soft/hard steer immediates from Client_Input_DriveControlTick clean source.

Evidence: reconstructed-exact/Client_Input_DriveControlTick.cpp SECTION 7
  hard-R 0xbf800000 = -1.0
  hard-L 0x3f800000 = +1.0
  soft-L 0xbf000000 = -0.5
  soft-R 0x3f000000 = +0.5
"""

from __future__ import annotations

from pathlib import Path

CLEAN = (
    Path(__file__).resolve().parents[1]
    / "reconstructed-exact"
    / "Client_Input_DriveControlTick.cpp"
)

HARD_R = 0xBF800000
HARD_L = 0x3F800000
SOFT_L = 0xBF000000
SOFT_R = 0x3F000000


def bits_to_f32(bits: int) -> float:
    import struct

    return struct.unpack("<f", struct.pack("<I", bits & 0xFFFFFFFF))[0]


def clean_documents_soft_immediates() -> bool:
    text = CLEAN.read_text(encoding="utf-8", errors="replace")
    return (
        "0xbf000000" in text.lower()
        and "0x3f000000" in text.lower()
        and "0xbf800000" in text.lower()
        and "0x3f800000" in text.lower()
    )


def soft_band_values() -> tuple[float, float]:
    return bits_to_f32(SOFT_L), bits_to_f32(SOFT_R)


def hard_band_values() -> tuple[float, float]:
    return bits_to_f32(HARD_L), bits_to_f32(HARD_R)
